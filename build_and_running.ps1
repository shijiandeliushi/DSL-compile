# HomeLang Project Build Script (PowerShell - English Version)
# Follows the exact command sequence provided by user

Write-Host "--- Starting Build Process ---" -ForegroundColor Cyan

# 1. cd lexer/src
Write-Host "[Step 1] Entering lexer/src..." -ForegroundColor Yellow
Set-Location lexer/src

# 2. win_flex lexer.l
Write-Host "[Step 2] Running win_flex..." -ForegroundColor Yellow
& win_flex lexer.l
if ($LASTEXITCODE -ne 0) { Write-Host "Flex failed"; exit $LASTEXITCODE }

# 3 & 4. cd .. / cd ..
Write-Host "[Step 3 & 4] Returning to root..." -ForegroundColor Yellow
Set-Location ../..

# 5. win_bison
Write-Host "[Step 5] Running win_bison..." -ForegroundColor Yellow
& win_bison -d parser\parser.y -o parser\parser.tab.c
if ($LASTEXITCODE -ne 0) { Write-Host "Bison failed"; exit $LASTEXITCODE }

# 6. GCC Compile
Write-Host "[Step 6] Compiling with GCC..." -ForegroundColor Yellow
# Added -Icodegen to ensure codegen.h is found
& gcc parser\parser.tab.c lexer\src\lex.yy.c parser\ast.c parser\symbol.c semantic\semantic.c codegen\codegen.c -Iparser -Icodegen -o dsl.exe

if ($LASTEXITCODE -ne 0) {
    Write-Host "[ERROR] GCC Compilation failed." -ForegroundColor Red
    exit $LASTEXITCODE
}

Write-Host "[SUCCESS] Build complete: dsl.exe" -ForegroundColor Green

# 7. Run dsl.exe
Write-Host "[Step 7] Running compiler..." -ForegroundColor Yellow
if (Test-Path "./dsl.exe") {
    & ./dsl.exe
} else {
    Write-Host "[ERROR] dsl.exe not found." -ForegroundColor Red
}

Write-Host "`nProcess finished. Press any key to exit..."
$null = [Console]::ReadKey()