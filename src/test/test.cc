#include <gtest/gtest.h>

#include "../app/controller/controller.h"

TEST(Test, parse_data) {
  s21::ModelFacade model;
  s21::Controller contr(&model);
  if (!contr.ParseData("../datasets/emnist-letters/emnist-letters-train.csv")) {
    SUCCEED();
  } else {
    FAIL();
  }
  if (contr.DataIsEmpty()) {
    FAIL();
  } else {
    SUCCEED();
  }
}

TEST(Test, parse_weights) {
  s21::ModelFacade model;
  s21::Controller contr(&model);
  if (!contr.ParseWeights(1, "../datasets/emnist-letters/weights_2sloya.txt")) {
    SUCCEED();
  } else {
    FAIL();
  }
  if (contr.WeightsIsEmpty()) {
    FAIL();
  } else {
    SUCCEED();
  }
}

TEST(Test, training_auto_graph) {
  s21::ModelFacade model;
  s21::Controller contr(&model);
  if (!contr.ParseData("../datasets/emnist-letters/emnist-letters-train.csv")) {
    contr.CreateNetwork(0, 2, true);
    std::vector<s21::Trainer::TrainerInfo> info = contr.Training(1, 0);
    EXPECT_TRUE(info[0].error < 0.4);
    EXPECT_TRUE(info[0].accuracy >= 50);
    EXPECT_TRUE(info[0].time < 70);
  } else {
    FAIL();
  }
}

TEST(Test, training_auto_matrix) {
  s21::ModelFacade model;
  s21::Controller contr(&model);
  if (!contr.ParseData("../datasets/emnist-letters/emnist-letters-train.csv")) {
    contr.CreateNetwork(1, 2, true);
    std::vector<s21::Trainer::TrainerInfo> info = contr.Training(1, 0);
    EXPECT_TRUE(info[0].error < 0.4);
    EXPECT_TRUE(info[0].accuracy >= 50);
    EXPECT_TRUE(info[0].time < 70);
  } else {
    FAIL();
  }
}

TEST(Test, training_cross_matrix) {
  s21::ModelFacade model;
  s21::Controller contr(&model);
  if (!contr.ParseData("../datasets/emnist-letters/emnist-letters-train.csv")) {
    contr.CreateNetwork(1, 2, true);
    std::vector<s21::Trainer::TrainerInfo> info = contr.Training(1, 2);
    EXPECT_TRUE(info[0].error < 0.4);
    EXPECT_TRUE(info[0].accuracy >= 50);
    EXPECT_TRUE(info[0].time < 70);
  } else {
    FAIL();
  }
}

TEST(Test, testing_auto_graph) {
  s21::ModelFacade model;
  s21::Controller contr(&model);
  if (!contr.ParseWeights(0, "../datasets/emnist-letters/weights_2sloya.txt")) {
    contr.ParseData("../datasets/emnist-letters/emnist-letters-test.csv");
    s21::Tester::TestingInfo info = contr.Testing(1);
    EXPECT_TRUE(info.error < 0.5);
    EXPECT_TRUE(info.accuracy >= 70);
    EXPECT_TRUE(info.f_measure >= 0.0008);
    EXPECT_TRUE(info.precision > 0.001);
    EXPECT_TRUE(info.recall > 0.0006);
  } else {
    FAIL();
  }
}
TEST(Test, testing_experiment_save) {
  s21::ModelFacade model;
  s21::Controller contr(&model);
  if (!contr.ParseWeights(0, "../datasets/emnist-letters/weights_2sloya.txt")) {
    contr.ParseData("../datasets/emnist-letters/emnist-letters-test.csv");
    double time = contr.Experiment(2);
    contr.SaveWeights("test_weights.txt");
    EXPECT_TRUE(time < 3);
  } else {
    FAIL();
  }
}

TEST(Test, testing_auto_matrix) {
  s21::ModelFacade model;
  s21::Controller contr(&model);
  if (!contr.ParseWeights(1, "../datasets/emnist-letters/weights_2sloya.txt")) {
    contr.ParseData("../datasets/emnist-letters/emnist-letters-test.csv");
    s21::Tester::TestingInfo info = contr.Testing(1);
    EXPECT_TRUE(info.error < 0.3);
    EXPECT_TRUE(info.accuracy >= 70);
    EXPECT_TRUE(info.f_measure >= 0.0008);
    EXPECT_TRUE(info.precision > 0.001);
    EXPECT_TRUE(info.recall > 0.0006);
  } else {
    FAIL();
  }
}

TEST(Test, testing_img_matrix) {
  s21::ModelFacade model;
  s21::Controller contr(&model);
  std::vector<float> example{
      2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   7,   32,  37,  37,  37,  37,  37,  37,  37,
      32,  9,   4,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   2,   75,  201, 217, 217, 217, 217, 217, 217, 217, 203, 140,
      125, 82,  39,  37,  37,  37,  37,  37,  37,  32,  9,   2,   0,   0,   0,
      0,   2,   80,  229, 250, 253, 254, 254, 254, 254, 254, 254, 250, 249, 233,
      217, 217, 217, 217, 217, 217, 217, 203, 138, 63,  2,   0,   0,   0,   0,
      20,  109, 140, 203, 217, 217, 217, 222, 245, 250, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 246, 125, 4,   0,   0,   0,   0,   0,   4,
      9,   32,  37,  37,  37,  51,  114, 140, 204, 222, 249, 254, 255, 254, 254,
      250, 250, 252, 254, 250, 127, 4,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   4,   9,   33,  83,  227, 254, 254, 247, 208, 140, 129,
      191, 252, 250, 127, 4,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   4,   116, 245, 254, 246, 164, 47,  9,   9,   129, 250,
      250, 127, 4,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   21,  172, 252, 251, 175, 36,  1,   0,   4,   114, 245, 250, 139,
      8,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      37,  215, 254, 233, 84,  3,   0,   0,   1,   64,  227, 251, 159, 16,  0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   37,  217,
      254, 222, 52,  1,   0,   0,   4,   115, 245, 250, 129, 5,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   32,  203, 254, 246,
      132, 24,  5,   5,   36,  177, 252, 249, 125, 4,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   8,   127, 246, 254, 234, 173,
      129, 129, 177, 246, 254, 232, 81,  2,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   46,  207, 253, 254, 252, 250, 250,
      252, 254, 245, 159, 22,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   7,   90,  207, 245, 250, 254, 254, 250, 243,
      163, 35,  1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   7,   46,  114, 140, 203, 203, 140, 113, 33,  1,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   4,   9,   32,  32,  9,   4,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0};
  if (!contr.ParseWeights(1, "../datasets/emnist-letters/weights_2sloya.txt")) {
    contr.Testing(1);
    EXPECT_TRUE(2 == contr.TestIMG(example));
  } else {
    FAIL();
  }
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}