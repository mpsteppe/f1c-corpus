#include "f1c/bootstrap/application.hpp"
#include "f1c/config/ini_document.hpp"
#include "f1c/content/inventory.hpp"
#include "f1c/platform/install_root.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace {

void require(bool condition, const char* message) {
    if (!condition) {
        throw std::runtime_error(message);
    }
}

}  // namespace

int main() {
    const auto root = std::filesystem::temp_directory_path() / "f1c_replacement_tests";
    std::error_code error;
    std::filesystem::remove_all(root, error);
    std::filesystem::create_directories(root / "SeasonData");
    {
        std::ofstream ini(root / "Config.ini");
        ini << "[Video]\nWidth = 1920\nHeight=1080\n";
    }
    {
        std::ofstream content(root / "SeasonData" / "sample.mas", std::ios::binary);
        content << "MAS";
    }

    const auto document = f1c::config::IniDocument::load(root / "Config.ini");
    require(document.section_count() == 1, "INI section count mismatch");
    require(document.key_count() == 2, "INI key count mismatch");
    require(document.get("Video", "Width") == std::optional<std::string>("1920"),
            "INI value mismatch");

    const auto inventory = f1c::content::scan_installation(root);
    require(inventory.files == 2, "inventory file count mismatch");
    require(inventory.extensions.at(".mas") == 1, "MAS inventory mismatch");

    const auto resolved = f1c::platform::resolve_install_root(
        root / "F1ChallengeReplacement.exe", root);
    require(resolved == std::filesystem::weakly_canonical(root),
            "installation root mismatch");

    const std::vector<std::wstring> arguments{
        L"F1ChallengeReplacement.exe", L"--inventory", L"--root", root.wstring()};
    const auto options = f1c::bootstrap::parse_options(
        arguments, root / "F1ChallengeReplacement.exe");
    require(options.inventory_only, "inventory option missing");
    require(options.requested_root == root, "root option mismatch");

    std::filesystem::remove_all(root, error);
    std::cout << "replacement bootstrap tests passed\n";
    return 0;
}
