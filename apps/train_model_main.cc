#include "core/momentum-prediction/momentum_training_data_factory.h"
#include "core/momentum-prediction/momentum_model.h"
#include "core/volatility-prediction/volatility_training_data_factory.h"
#include "core/volatility-prediction/volatility_model.h"
#include "core/volatility-prediction/volatility_classifier.h"
#include "core/momentum-prediction/momentum_classifier.h"

using std::vector;

int main() {
    vector<string> file_paths = {"acciona.csv"};
    // Momentum Prediction
    finadvisor::MomentumTrainingDataFactory momentum_factory;
    momentum_factory = momentum_factory.ValidateFiles(file_paths);
    finadvisor::MomentumModel momentum_model;
    momentum_model = momentum_model.ValidateFile(momentum_factory.WriteToOutputFile(momentum_factory));
    finadvisor::MomentumClassifier momentum_classifier;
    momentum_classifier.ValidateFile("testmomentumdata.txt");
    momentum_classifier.CalculateValidationAccuracy(momentum_model, 5);

    // Volatility Prediction
    finadvisor::VolatilityTrainingDataFactory volatility_factory;
    volatility_factory = volatility_factory.ValidateFiles(file_paths);
    finadvisor::VolatilityModel volatility_model;
    volatility_model.ValidateFile(volatility_factory.WriteToOutputFile(volatility_factory));
    finadvisor::VolatilityClassifier volatility_classifier;
    volatility_classifier.ValidateFile("testvolatilitydata.txt");
    volatility_classifier.CalculateValidationAccuracy(volatility_model, 5);
}