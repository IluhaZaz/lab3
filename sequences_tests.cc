#include <gtest/gtest.h>
#include <sequences/sequence.h>

using namespace sequence;
using namespace std;

using ProgressionPtr = std::shared_ptr<Progression>;

int main() {
const auto p = ArifProgression(1,1,1);
return 0;
}

/*

TEST(SequencesTests, GetNElemTest) {
    // Arrange
    Sequence s;
    // Act
    s.add_progression(make_shared<ArifProgression>(1, 2, 5));
    // Assert
    EXPECT_EQ(s.get_n_elem(3), 4);
}
TEST(SequencesTests, GetNElemTest2) {
    // Arrange
    Sequence s;
    ProgressionPtr pr = make_shared<ArifProgression>(1, 2, 5);
    ProgressionPtr pr2 = make_shared<GeomProgression>(2, 2, 3);
    // Act
    s.add_progression(pr);
    s.add_progression(pr2);
    // Assert
    EXPECT_EQ(s.get_n_elem(7), 4);
}

TEST(SequencesTests, GetNElemTest3) {
    // Arrange
    Sequence s;
    ProgressionPtr pr = make_shared<ArifProgression>(1, 2, 5);
    // Act
    s.add_progression(pr);
    // Assert
    EXPECT_EQ(s.get_n_elem(7), 8);
}

TEST(SequencesTests, GetSum) {
    // Arrange
    Sequence s;
    ProgressionPtr pr = make_shared<ArifProgression>(3, 0, 5);
    // Act
    s.add_progression(pr);

    // Assert
    EXPECT_EQ(s.get_sum(4), 18);
}

TEST(SequencesTests, GetSum2) {
    // Arrange
    Sequence s;
    ProgressionPtr pr = make_shared<ArifProgression>(3, 0, 5);
    ProgressionPtr pr2 = make_shared<GeomProgression>(2, 2, 3);
    // Act
    s.add_progression(pr);
    s.add_progression(pr2);
    // Assert
    EXPECT_EQ(s.get_sum(7), 36);
}

TEST(SequencesTests, GetMaxSum) {
    // Arrange
    Sequence s;
    ProgressionPtr pr = make_shared<ArifProgression>(1, 1, 5);
    ProgressionPtr pr2 = make_shared<GeomProgression>(2, 2, 3);
    // Act
    s.add_progression(pr);
    s.add_progression(pr2);
    // Assert
    EXPECT_EQ(*(s.get_prog_with_max_sum(3)), *pr2);
}

TEST(SequencesTests, GetMaxSum2) {
    // Arrange
    Sequence s;
    ProgressionPtr pr = make_shared<ArifProgression>(1, 1, 2);
    ProgressionPtr pr2 = make_shared<ArifProgression>(-1, 3, 2);
    // Act
    s.add_progression(pr);
    s.add_progression(pr2);
    // Assert
    EXPECT_EQ(*(s.get_prog_with_max_sum(3)), *pr2);
}

TEST(SequencesTests, ErrorTest) {
    EXPECT_ANY_THROW(make_shared<GeomProgression>(0, 1, 3));
}

TEST(SequencesTests, ErrorTest2) {
    Sequence s;
    EXPECT_ANY_THROW(s.get_sum(1));
}

TEST(SequencesTests, OverwriteTest) {
    Sequence s;
    ProgressionPtr pr = make_shared<ArifProgression>(1, 1, 2);
    ProgressionPtr pr2 = make_shared<ArifProgression>(-1, 3, 2);
    s.add_progression(pr);
    s.overwrite(0, pr2);
    EXPECT_EQ(s[0], *pr2);
}
*/
