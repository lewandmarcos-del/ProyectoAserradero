cd "C:\ESCRITORIO\UTN\Programacion_II\ProyectoAserradero"
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "   Sincronizar proyecto con GitHub" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "Archivos modificados localmente:" -ForegroundColor Yellow
git status --short
Write-Host ""
Write-Host "Descargando cambios del repositorio remoto..." -ForegroundColor Cyan
git pull origin main --no-edit --allow-unrelated-histories
if ($LASTEXITCODE -ne 0) {
    Write-Host "¡Hay conflictos! Resuélvelos manualmente y luego ejecuta:" -ForegroundColor Red
    Write-Host "git add ." -ForegroundColor Yellow
    Write-Host "git commit -m 'Resolver conflictos'" -ForegroundColor Yellow
    Write-Host "git push" -ForegroundColor Yellow
    Read-Host "Presione Enter para salir"
    exit
}
Write-Host ""
Write-Host "Archivos después del pull:" -ForegroundColor Yellow
git status --short
Write-Host ""
$mensaje = Read-Host "Ingrese la descripcion de los cambios locales"
if (-not $mensaje) { $mensaje = "Actualizacion automatica" }
git add .
git commit -m "$mensaje"
git push origin main
Write-Host ""
Write-Host "========================================" -ForegroundColor Green
Write-Host "   ¡Todo sincronizado en GitHub!" -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Green
Read-Host "Presione Enter para salir"