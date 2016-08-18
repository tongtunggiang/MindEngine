#ifndef PATTERNNODE_H
#define PATTERNNODE_H

#include "ReteNode.h"

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

class PatternNode : public ReteNode
{

public:

	/**
	 * @brief Default constructor.
	 */
	PatternNode();

	/**
	 * @brief A pattern node is a node which performs tests to the database
	 * (aka. working memory) and passes down all matched facts. Pattern nodes
	 * are also referred as alpha nodes.
	 * @return true if this node is a pattern node.
	 */
	virtual bool isPatternNode() const;

	virtual bool addSuccessorNode(ReteNode *node);

};

}

#endif // PATTERNNODE_H
