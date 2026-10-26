#include "f1c/bootstrap/application.hpp"

#include "f1c/config/ini_document.hpp"
#include "f1c/content/inventory.hpp"
#include "f1c/logging/logger.hpp"
#include "f1c/platform/install_root.hpp"

#include <sstream>
#include <stdexcept>

namespace f1c::bootstrap {

Options parse_options(const std::vector<std::wstring>& arguments,
                      const std::filesystem::path& executable_path) {
    Options options;
    options.executable_path = executable_path;
    for (std::size_t index = 1; index < arguments.size(); ++index) {
        const auto& argument = arguments[index];
        if (argument == L"--inventory") {
            options.inventory_only = true;
        } else if (argument == L"--root") {
            if (++index >= arguments.size()) {
                throw std::invalid_argument("--root requires a directory");
            }
            options.requested_root = arguments[index];
        } else {
            throw std::invalid_argument("unknown command-line argument");
        }
    }
    return options;
}

int Application::run(const Options& options) const {
    const auto root = platform::resolve_install_root(
        options.executable_path, options.requested_root);
    logging::Logger log(root / "F1ChallengeReplacement.log");
    log.info("replacement engine bootstrap starting");
    log.info("installation root: " + root.string());

    const auto config_path = root / "Config.ini";
    if (std::filesystem::is_regular_file(config_path)) {
        const auto config = config::IniDocument::load(config_path);
        std::ostringstream message;
        message << "Config.ini parsed: " << config.section_count()
                << " sections, " << config.key_count() << " keys";
        log.info(message.str());
    } else {
        log.info("Config.ini not present; continuing with bootstrap defaults");
    }

    const auto inventory = content::scan_installation(root);
    log.info(content::render_inventory(inventory));
    if (options.inventory_only) {
        log.info("inventory-only bootstrap completed");
        return 0;
    }

    log.info("simulation and presentation subsystems are not implemented yet");
    log.info("replacement engine bootstrap completed cleanly");
    return 0;
}

}  // namespace f1c::bootstrap
