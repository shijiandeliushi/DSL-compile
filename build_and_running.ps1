# HomeLang Build Script (English Version to avoid encoding issues)

Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "   HomeLang Compiler Build System" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan

# 1. Run Bison
Write-Host "[1/4] Running win_bison..." -ForegroundColor Yellow
& win_bison -d parser/parser.y -o parser/parser.tab.c
if ($LASTEXITCODE -ne 0) {
    Write-Host "[ERROR] Bison failed." -ForegroundColor Red
    exit $LASTEXITCODE
}

# 2. Run Flex
Write-Host "[2/4] Running win_flex..." -ForegroundColor Yellow
& win_flex -o lexer/src/lex.yy.c lexer/src/lexer.l
if ($LASTEXITCODE -ne 0) {
    Write-Host "[ERROR] Flex failed." -ForegroundColor Red
    exit $LASTEXITCODE
}

# 3. Compile with GCC
Write-Host "[3/4] Compiling with GCC..." -ForegroundColor Yellow
& gcc parser/parser.tab.c `
    lexer/src/lex.yy.c `
    parser/ast.c `
    parser/symbol.c `
    parser/semantic.c `
    codegen/codegen.c `
    -Iparser -Icodegen `
    -o dsl.exe

if ($LASTEXITCODE -ne 0) {
    Write-Host "[ERROR] GCC Compilation failed." -ForegroundColor Red
    exit $LASTEXITCODE
}

Write-Host "[SUCCESS] Build complete: dsl.exe" -ForegroundColor Green
Write-Host "==========================================" -ForegroundColor Cyan

# 4. Run Compiler
Write-Host "[4/4] Starting Compiler..." -ForegroundColor Yellow
if (Test-Path "./dsl.exe") {
    & ./dsl.exe
} else {
    Write-Host "[ERROR] dsl.exe not found." -ForegroundColor Red
}

Write-Host "`nProcess finished. Press any key to exit..."
$null = [Console]::ReadKey()