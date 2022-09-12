#include <visualizer/automated_finadvisor_app.h>

using finadvisor::visualizer::AutomatedFinadvisorApp;

void prepareSettings(AutomatedFinadvisorApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(AutomatedFinadvisorApp, ci::app::RendererGl, prepareSettings);