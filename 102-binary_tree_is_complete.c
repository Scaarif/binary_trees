#include "binary_trees.h"
/* queue functions */

/**
 * create_queue - creates a queue
 * Return: pointer to the queue
 */
queue_t *create_queue(void)
{
	queue_t *queue;

	/* allocate memory to the queue */
	queue = malloc(sizeof(queue_t));
	if (queue == NULL)
		return (NULL); /* malloc failed */
	/* assign values to queue */
	queue->front = queue->rear = NULL;
	return (queue);
}

/**
 * enqueue - adds/inserts a node to the rear of the queue
 * @queue: pointer to the queue in which to insert a node
 * @node: pointer to the node to insert
 * Return: the added node's value
 */
int enqueue(queue_t *queue, const binary_tree_t *node)
{
	qnode_t *new;
	/* check if node is defined */
	if (node)
	{
		/* create new qnode */
		new = malloc(sizeof(qnode_t));
		if (new == NULL) /* malloc failure */
			return (-1);
		new->node = (binary_tree_t *)node;
		new->next = NULL;
		/* check if queue is empty */
		/* printf("enqueue: \n"); */
		if (queue->rear)
		{
			queue->rear->next = new;
			/* update queue->rear */
			queue->rear = new;
		}
		else /* queue empty */
		{
			queue->rear = new;
			queue->front = queue->rear;
		}
		return (queue->rear->node->n);
	}
	return (-1);
}

/**
 * dequeue - removes a node from the queue (the front)
 * @queue: pointer to the queue
 * Return: the removed qnode's node
 */
binary_tree_t *dequeue(queue_t *queue)
{
	qnode_t *temp;
	binary_tree_t *node;

	/* printf("dequeue:\n"); */
	if (queue->front)
	{
		temp = queue->front;
		/* update rear if it points to same node */
		if (queue->front == queue->rear)
			queue->rear = NULL;
		/* update queue->front */
		queue->front = queue->front->next;
		node = temp->node;
		free(temp);
		return (node);
	}
	return (NULL); /* empty queue - front is NULL */
}

/**
 * delete_queue - deletes a queue
 * @queue: pointer to the queue to delete
 * Return: Nothing
 */
void delete_queue(queue_t *queue)
{
	qnode_t *temp;

	/* check if queue is empty, free any nodes */
	while (queue->front)
	{
		temp = queue->front;
		/* update queue->front */
		queue->front = queue->front->next;
		/* free front */
		free(temp);
	}
	/* free queue */
	free(queue);
}

/**
 * binary_tree_is_complete - goes through a binary tree using
 * level-order trversal, also referred to as: Bredth First traversal
 * done using a QUEUE to check if it is a COMPLETE tree
 * NOTE:  atree with all levels full except maybe the last
 * level, which is filled left first towards right
 * This function checks for instanes where a right node has
 * child(ren) while the left node doesn't or isn't a full node
 * @tree: pointer to the root node of the tree to traverse
 * Return: Nothing
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *temp;
	queue_t *queue = create_queue();

	if (tree != NULL)
	{
		/* add tree(root) to queue */
		enqueue(queue, tree);
		/* printf("entering while loop\n"); */
		while (queue->front) /* queue not empty */
		{
			/* process current node */
			temp = dequeue(queue);
			/* func(temp->n); */
			/* enqueue current node's children if any */
			if (temp->left)
			{
				enqueue(queue, temp->left);
			}
			if (temp->right)
			{
				/* check if right and sib have kids */
				if (!temp->left) /* node has no left child */
					return (0);
				if (temp->left && (temp->right->left || temp->right->right))
				{ /* right child has a kid or kids, check if left has both */
					if (!temp->left->left || !temp->left->right)
						return (0);
				}
				enqueue(queue, temp->right);
			}
		}
		/* printf("left while loop\n"); */
		/* delete queue once done */
		delete_queue(queue);
		return (1); /* passes as complete */
	}
	delete_queue(queue);
	return (0); /* tree is NULL */
}
