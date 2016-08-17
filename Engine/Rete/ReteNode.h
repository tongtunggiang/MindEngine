#ifndef RETENODE_H
#define RETENODE_H

#include <vector>

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
 * @brief The base class of every node in Rete network. Every node
 * type (root node, pattern node, join node and rule node) is derived
 * from this type.
 */
class ReteNode
{

public:

    ReteNode();

protected:

    /**
     * @brief The array holds the nodes can be visited from current node.
     * Note that there is no opposite way, since the graph is directed acyclic.
     */
    std::vector<ReteNode*> successorNodes;

};

}

#endif // RETENODE_H
