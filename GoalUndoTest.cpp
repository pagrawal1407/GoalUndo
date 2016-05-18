/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

using namespace std;
class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST (GoalUndoTest, CheckUndoGoal)
{
  GoalUndo G;
  string goal = "Draw Triangle";
  string check = "";
  G.addOperation (goal);
  G.undoGoal();
  ASSERT_EQ (check, G.getGoal());
}

TEST (GoalUndoTest, CheckUndoGoalEmpty)
{
  GoalUndo G;
  G.undoGoal();
  string check = "";
  ASSERT_EQ (check, G.getGoal());
}

TEST (GoalUndoTest, UndoOperationEmptyCheck)
{
  GoalUndo G;
  string check = "";
  G.undoOperation();
  ASSERT_EQ (check, G.getGoal());
}

TEST (GoalUndoTest, UndoOperationWithSingleOperation)  
{
  GoalUndo G;
  string goal = "Draw Triangle";
  string check = "";
  G.addOperation (goal);
  G.undoOperation();
  ASSERT_EQ (check, G.getGoal());
}

TEST (GoalUndoTest, UndoOperationWithMultipleOperations)
{
  GoalUndo G;
  string goal1 = "Draw Triangle";
  string goal2 = "Draw Square";
  G.addOperation (goal1);
  G.addOperation (goal2);
  G.undoOperation();
  ASSERT_EQ (goal1, G.getGoal());
}

TEST (GoalUndoTest, UndoOperationsEmptyCheck)
{
  GoalUndo G;
  string check = "";
  string operation = "Draw Triangle";
  G.undoOperation(operation);
  ASSERT_EQ (check, G.getGoal());
}

TEST (GoalUndoTest, UndoOperationsWithSingleOperation1Argument)  
{
  GoalUndo G;
  string operation = "Draw Triangle";
  string check = "";
  G.addOperation (operation);
  G.undoOperation(operation);
  ASSERT_EQ (check, G.getOperations());
}

TEST (GoalUndoTest, UndoOperationsWithMultipleOperations1Argument)
{
  GoalUndo G;
  string goal1 = "Draw Triangle";
  string operation = "Draw Square";
  G.addOperation (goal1);
  G.addOperation (operation);
  G.undoOperation(goal1);
  ASSERT_EQ (goal1, G.getGoal());
}

TEST (GoalUndoTest, UndoOperationsWithMultipleOperationsCheck1Argument)
{
  GoalUndo G;
  string goal1 = "Draw Triangle";
  string operation = "Draw Square";
  string unmatch = "abc";
  G.addOperation (goal1);
  G.addOperation (operation);
  G.undoOperation(unmatch);
  ASSERT_EQ (goal1, G.getGoal());
}


TEST (GoalUndoTest, CheckGetGoalEmpty)
{
  GoalUndo G;
  string check = "";
  ASSERT_EQ (check, G.getGoal());
}

TEST (GoalUndoTest, CheckGetGoal)
{
  GoalUndo G;
  string goal1 = "Draw Triangle";
  G.addOperation (goal1);
  ASSERT_EQ (goal1, G.getGoal());
}

TEST (GoalUndoTest, CheckGetOperationsEmpty)
{
  GoalUndo G;
  string check = "";
  ASSERT_EQ (check, G.getOperations());
}

TEST (GoalUndoTest, CheckGetOperations)
{
  GoalUndo G;
  string goal1 = "Draw Triangle";
  G.addOperation (goal1);
  ASSERT_EQ (goal1, G.getOperations());
}

TEST (GoalUndoTest, UndoOperationsWithMultipleOperations)
{
  GoalUndo G;
  string goal1 = "Draw Triangle";
  string operation = "Draw Square";
  string check = goal1 + " " + operation;
  G.addOperation (goal1);
  G.addOperation (operation);
  ASSERT_EQ (check, G.getOperations());
}

TEST (GoalUndoTest, CheckAddOperations2ArgumentsEmpty)
{
  GoalUndo G;
  string goal = "";
  G.addOperation (goal, goal);
  ASSERT_EQ (goal, G.getGoal());
}

TEST (GoalUndoTest, CheckAddOperations2Arguments)
{
  GoalUndo G;
  string goal = "";
  string operation = "Draw Triangle";
  G.addOperation (goal, operation);
  ASSERT_EQ (goal, G.getGoal());
}


TEST (GoalUndoTest, CheckAddOperations2ArgumentsAgain)
{
  GoalUndo G;
  string goal = "Draw Triangle";
  string operation = "";
  G.addOperation (goal, operation);
  ASSERT_EQ (operation, G.getGoal());
}


TEST (GoalUndoTest, CheckAddOperations2ArgumentsNonEmpty)
{
  GoalUndo G;
  string goal = "Draw Triangle";
  G.addOperation (goal, goal);
  ASSERT_EQ (goal, G.getGoal());
}

TEST (GoalUndoTest, CheckAddOperations1ArgumentEmpty)
{
  GoalUndo G;
  string goal = "";
  G.addOperation (goal);
  ASSERT_EQ (goal, G.getGoal());
}


TEST (GoalUndoTest, CheckAddOperations1ArgumentsNotEmpty)
{
  GoalUndo G;
  string goal = "Draw Triangle";
  G.addOperation (goal);
  ASSERT_EQ (goal, G.getGoal());
}


TEST (GoalUndoTest, CheckAddOperations1ArgumentsNonEmptyAgain)
{
  GoalUndo G;
  string goal = "Draw Triangle";
  string operation = "Draw Square";
  G.addOperation (goal);
  G.addOperation (operation);
  ASSERT_EQ (goal, G.getGoal());
}
