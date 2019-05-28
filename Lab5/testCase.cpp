#include "main.h"
#include "catch.hpp"

/*
\newpage
\fbox{\textbf{Test Cases}}
\newline These are the test cases I used to ensure my queue was working as intended. All of the test cases passed so I can conclude that everything is working as intended.
\newline I have include a compact version of the unit testing below.
\verbatiminput{testCases.txt}
*/

Queue* queue;

TEST_CASE("Make an empty Queue")
{
	queue = new Queue;
	REQUIRE(queue != nullptr);
	REQUIRE(queue->head == nullptr);
	REQUIRE(queue->tail == nullptr);
}

TEST_CASE("Pushing to the Queue")
{
	REQUIRE(queue->head == nullptr);
	queue->push("alpha");
	REQUIRE(queue->tail != nullptr);
	queue->push("beta");
	REQUIRE(queue->tail->key == "beta");
	queue->push("gamma");
	REQUIRE(queue->tail->key == "gamma");
	queue->push("delta");
	REQUIRE(queue->tail->key == "delta");
	queue->push("epsilon");
	REQUIRE(queue->tail->key == "epsilon");
}

TEST_CASE("Pop from the Queue")
{
	REQUIRE(queue->head->key == "alpha");
	queue->pop();
	REQUIRE(queue->head->key == "beta");
	queue->pop();
	REQUIRE(queue->head->key == "gamma");
	queue->pop();
	REQUIRE(queue->head->key == "delta");
	queue->pop();
	REQUIRE(queue->head->key == "epsilon");
	queue->pop();
	REQUIRE(queue->head == nullptr);
}

