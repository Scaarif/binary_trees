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

	if (queue->front)
	{
		temp = queue->front;
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
 * binary_tree_levelorder - goes through a binary tree using
 * level-order trversal, also referred to as: Bredth First traversal
 * is done using a QUEUE
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to be called for each node,
 * takes the value of the node as a parameter
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *temp;
	queue_t *queue = create_queue();

	if (tree != NULL)
	{
		/* add tree(root) to queue */
		enqueue(queue, tree);
		while (queue->front) /* queue not empty */
		{
			temp = dequeue(queue);
			/* process current node */
			func(temp->n);
			/* add current node's children to queue */
			if (temp->left)
				enqueue(queue, temp->left);
			if (temp->right)
				enqueue(queue, temp->right);
		}
		/* delete queue */
		delete_queue(queue);
	}
}
