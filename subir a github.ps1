cd "C:\ESCRITORIO\UTN\Programacion_II\ProyectoAserradero"
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "   Subir proyecto a GitHub" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "Archivos modificados:" -ForegroundColor Yellow
git status --short
Write-Host ""
$mensaje = Read-Host "Ingrese la descripcion de los cambios"
if (-not $mensaje) { $mensaje = "Actualizacion automatica" }
git add .
git commit -m "$mensaje"
git push
Write-Host ""
Write-Host "========================================" -ForegroundColor Green
Write-Host "   ¡Actualizado en GitHub!" -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Green
Read-Host "Presione Enter para salir"