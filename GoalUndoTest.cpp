/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
 
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

TEST(GoalUndoTest, testsingleoperation)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	ASSERT_EQ("Triangle",goal.getOperations());
}


TEST(GoalUndoTest, testmultipleoperation)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.addOperation("Square");
	goal.addOperation("Circle");
	goal.addOperation("Rect");
	
	ASSERT_EQ("Triangle Square Circle Rect",goal.getOperations());

	

}

TEST(GoalUndoTest, ListOfAllOperations)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.addOperation("Square");
	ASSERT_EQ("Triangle Square",goal.getOperations());
}


TEST(GoalUndoTest, TestGetGoal)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	
	ASSERT_EQ("Goal-1",goal.getGoal());
}

TEST(GoalUndoTest, TestEmptyGetGoal)
{
	GoalUndo goal;
	
	
	ASSERT_EQ("",goal.getGoal());
}


TEST(GoalUndoTest, TestUndoGoal)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.undoGoal();

	
	ASSERT_EQ("",goal.getGoal());
}



TEST(GoalUndoTest, TestUndoOperation)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.undoOperation();

	
	ASSERT_EQ("",goal.getOperations());
}

TEST(GoalUndoTest, TestUndoMultipleGoal)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.addOperation("Goal-2","Square");
	goal.addOperation("Goal-3", "Circle");

	goal.undoGoal();

	
	ASSERT_EQ("Goal-2",goal.getGoal());
}



TEST(GoalUndoTest, TestUndoallGoal)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.addOperation("Goal-2","Square");
	goal.addOperation("Goal-3", "Circle");

	goal.undoGoal();

	goal.undoGoal();
	goal.undoGoal();
	
	ASSERT_EQ("",goal.getGoal());
}


TEST(GoalUndoTest, TestUndoMultipleOperations)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.addOperation("Square");
	goal.addOperation("Circle");

	goal.undoOperation();

	goal.undoOperation();
	//goal.undoGoal();
	
	ASSERT_EQ("Triangle",goal.getOperations());
}


TEST(GoalUndoTest, TestUndoAllOperations)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.addOperation("Square");
	goal.addOperation("Circle");

	goal.undoOperation();

	goal.undoOperation();
	goal.undoOperation();
	
	ASSERT_EQ("",goal.getOperations());
}



TEST(GoalUndoTest, TestUndoDifferentGoals)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.addOperation("Square");
	goal.addOperation("Circle");
	goal.addOperation("Goal-2", "Rect");

	goal.undoOperation();

	goal.undoOperation();
	goal.undoOperation();
	
	ASSERT_EQ("Triangle",goal.getOperations());
}

TEST(GoalUndoTest, TestUndoDifferentOperations)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.addOperation("Square");
	goal.addOperation("Circle");
	goal.addOperation("Goal-2", "Rect");

	goal.undoOperation();
	goal.undoGoal();

	goal.undoOperation();
	goal.undoOperation();
	goal.undoGoal();
	
	ASSERT_EQ("",goal.getOperations());
	ASSERT_EQ("", goal.getGoal());
}

TEST(GoalUndoTest, Testaddemptyoperation)
{
	GoalUndo goal;
	goal.addOperation("Triangle");
	
	
	ASSERT_EQ("Triangle",goal.getGoal());
	
}


TEST(GoalUndoTest, TestUndoOperationswithname)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.addOperation("Triangle");
	goal.addOperation("Circle");
	goal.undoOperation("Triangle");
	
	ASSERT_EQ("Triangle Circle",goal.getOperations());
	//ASSERT_EQ("", goal.getGoal());
}

TEST(GoalUndoTest, TestUndoOperationswithdifferentname)
{
	GoalUndo goal;
	goal.addOperation("Goal-1","Triangle");
	goal.addOperation("Triangle");
	goal.addOperation("Circle");
	goal.undoOperation("Square");
	
	ASSERT_EQ("Triangle Triangle Circle",goal.getOperations());
	//ASSERT_EQ("", goal.getGoal());
}



