<!--
  Copilot / AI Agent instructions for this repository (Kaito)
  Generated: concise, actionable, and tailored to the current repo contents.
-->

## Hướng dẫn nhanh (phiên bản tiếng Việt) — Kho mã Kaito

- Trạng thái hiện tại: kho mã chỉ chứa một file cấu hình editor tại `.vscode/settings.json`. Chưa thấy thư mục `src/`, `tests/`, hoặc file dự án C# (`*.csproj`, `*.sln`). Nếu bạn thêm mã vào vị trí khác, cập nhật hướng dẫn này.

### Mục tiêu chính
- Trước khi sửa code, hỏi chủ repo (bạn) xác nhận ngôn ngữ/mục tiêu (bây giờ là C#/.NET). Hiện bạn không muốn mình scaffold dự án mới — mọi thay đổi lớn cần có xác nhận trước.

### Các bước kiểm tra nhanh (chạy ở gốc repo)
1. `ls -la` — xem cấu trúc thư mục.
2. `git status --porcelain -b` — kiểm tra branch và thay đổi chưa commit.
3. Tìm file báo hiệu dự án C# / Docker / Node:
   - `rg --hidden --glob '!node_modules' "\.csproj$|\.sln$|Program\.cs|Startup\.cs|package.json|Dockerfile" || true`
   - Nếu không có `rg`: `grep -R --line-number "<Project Sdk=|Program.cs|package.json|Dockerfile" . || true`
4. Nếu tìm thấy `.csproj`/`.sln` — dừng lại và chạy bước hướng dẫn C# bên dưới.

### Quy trình C# / .NET (nếu có file dự án)
- Kiểm tra môi trường: `dotnet --info` và `dotnet --list-sdks`.
- Restore + Build: `dotnet restore` → `dotnet build --no-restore -v minimal`.
- Chạy test (nếu có): `dotnet test` (tại root hoặc project test cụ thể).
- Chạy ứng dụng: `dotnet run --project <path/to/Project.csproj>`.
- Debug: mở Run view trong VS Code; nếu chưa có `.vscode/launch.json`, hỏi trước khi tạo cấu hình debug tự động.

### Quy tắc an toàn (không tự động scaffold)
- Bạn đã yêu cầu: không scaffold dự án mới. Nếu không có mã, dừng và hỏi chủ repo trước khi tạo `src/` hoặc `tests/`.

### Gợi ý workspace & cấu hình cần giữ nguyên
- Giữ nguyên các thiết lập trong `.vscode/settings.json` (ví dụ: `workbench.colorTheme`, `workbench.iconTheme`, `editor.fontFamily`).

### Tập quán và cấu trúc gợi ý
- Nếu cần tạo dự án sau này, dùng:
  - Source: `src/<project>`
  - Tests: `tests/<project>.Tests`
  - Cấu hình chung: `Directory.Build.props` nếu có nhiều project

### Điểm tích hợp cần lưu ý
- NuGet: kiểm tra `PackageReference` trong `.csproj`.
- Docker / Devcontainer: kiểm tra `Dockerfile` hoặc `.devcontainer/`.
- CI: `.github/workflows/` chưa có — hỏi bạn muốn dùng GitHub Actions hay Azure Pipelines.

### Khi sửa file trong repo
- Tạo commit nhỏ, rõ ràng (ví dụ: `fix: update README` hoặc `chore: add editor settings`).
- Nếu thêm file cấu hình (CI, launch.json, Directory.Build.props), mô tả thay đổi rõ trong PR và xin xác nhận trước.

---
Vui lòng xác nhận tiếp:
- Bạn đã chọn C#/.NET và hiện tại không muốn scaffold hay thêm CI — đúng không? Nếu có thêm chi tiết (ví dụ target framework, .NET 6/7/8), cho mình biết để mình cập nhật chính xác hơn.

