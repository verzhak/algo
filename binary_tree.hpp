
#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>
#include <utility>

template <typename T>
class CBinaryTree
{
	protected:

		typedef std::shared_ptr<CBinaryTree<T> > TBinaryTreePtr;

		T _value;
		const CBinaryTree<T> * _parent = nullptr;
		TBinaryTreePtr _left, _right;

		void move(CBinaryTree<T> && tree)
		{
			_value = tree._value;
			_parent = tree._parent;
			_left = tree._left;
			_right = tree._right;

			tree._parent = nullptr;
			tree._left.reset();
			tree._right.reset();
		}

	public:

		explicit CBinaryTree(const T & value)
		{
			_value = value;
		};

		CBinaryTree(CBinaryTree<T> && tree)
		{
			move(std::move(tree));
		}

		~CBinaryTree() {};

		inline T value() const { return _value; };
		inline operator bool() const { return _left || _right; };
		inline const CBinaryTree<T> & parent() const { return * _parent; };
		inline const TBinaryTreePtr left() const { return _left; };
		inline const TBinaryTreePtr right() const { return _right; };

		CBinaryTree<T> operator=(CBinaryTree<T> && tree)
		{
			move(std::move(tree));

			return * this;
		}

		void insert(CBinaryTree<T> && tree)
		{
			TBinaryTreePtr & elem = _value > tree._value ? _left : _right;

			if(elem)
				elem->insert(std::move(tree));
			else
			{
				elem = std::make_shared<CBinaryTree<T> >(CBinaryTree<T>(std::move(tree)));
				elem->_parent = this;
			}
		}

		template <typename U>
		friend std::ostream & operator<<(std::ostream & stream, const CBinaryTree<U> & tree);
};

template <typename U>
std::ostream & operator<<(std::ostream & stream, const CBinaryTree<U> & tree)
{
	stream << tree._value << " [ ";
	
	if(tree._left)
		stream << * tree._left;
	
	stream << ", ";
	
	if(tree._right)
		stream << * tree._right;
	
	stream << " ] ";

	return stream;
}

template<typename T>
size_t max_path_length(const CBinaryTree<T> & tree)
{
	size_t left_size = 0, right_size = 0;
	auto & left = tree.left(), & right = tree.right();

	if(left)
		left_size = max_path_length(* left);

	if(right)
		right_size = max_path_length(* right);

	return std::max(left_size, right_size) + 1;
}

#endif

