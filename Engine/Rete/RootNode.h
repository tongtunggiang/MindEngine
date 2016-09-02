#ifndef ROOTNODE_H
#define ROOTNODE_H

#include "ReteNode.h"

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
 * @brief Represents the entry node of the Rete network.
 * The database will be passed into this node, whose responsibility is
 * forwarding them to the successor nodes, which are pattern nodes.
 */
class RootNode : public ReteNode
{

public:

	/**
	 * @brief Default constructor for root nodes, called upon creating Rete network;
	 */
	RootNode();

	/**
	 * @brief Rete network has an entry point called root node. The database
	 * will be passed into the network through this node.
	 * @return true if this node is a root node.
	 */
	virtual bool isRootNode() const;

	/**
	 * @brief Add a successor node to current list.
	 * Successor nodes of a root node must be pattern nodes.
	 * @param node The pattern node is being added as the successor node of this node.
	 * @return true if the node is successfully added, otherwise return false.
	 */
	virtual bool addSuccessorNode(ReteNode* node);

};

}

#endif
