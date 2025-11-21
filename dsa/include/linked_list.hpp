#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include <iostream>
#include <memory>

namespace ragc
{
    template <typename T>
    class LinkedList
    {
    private:
        struct Node;

        using NodePtr = std::unique_ptr<Node>;

        struct Node
        {
            T value;
            NodePtr next;

            Node(const T &data) : value(data), next(nullptr) {}
            ~Node()
            {
                std::cout << "Node with value: " << value << " deleted!" << std::endl;
            }
        };

        NodePtr head_;
        size_t size_;

    public:
        LinkedList() : head_(nullptr) {}

        void insert_at_head(const T &data)
        {
            NodePtr new_node = std::make_unique<Node>(data);

            new_node->next = std::move(head_);

            head_ = std::move(new_node);

            ++size_;
        }

        void insert_at_tail(const T &data)
        {
            auto new_node = std::make_unique<Node>(data);
            if (!head_)
            {
                head_ = std::move(new_node);
                return;
            }

            Node *current = head_.get();

            while (current->next)
            {
                current = current->next.get();
            }

            current->next = std::move(new_node);
        }

        T remove_from_head()
        {
            if (!head_)
            {
                throw std::out_of_range("Empty List");
            }

            T removed_value = std::move(head_->value);

            head_ = std::move(head_->next);

            return removed_value;
        }

        T remove_from_tail()
        {
            if (!head_)
            {
                throw std::out_of_range("Empty List");
            }

            if(!head_->next)
            {
                T value = std::move(head_->value);

                head_.reset();

                return value;
            }

            Node *current = head_.get();

            while (current->next && current->next->next)
            {
                current = current->next.get();
            }

            NodePtr old_node = std::move(current->next);
            T value_to_return = std::move(old_node->value);

            return value_to_return;
        }

        void remove()
        {
        }

        void is_empty()
        {
        }

        bool search(T key) const
        {
            return false;
        }

        size_t size() const
        {
            return size_;
        }

        void print()
        {
        }

        bool insertion_sort_crescent()
        {
            return false;
            /* if (!head_ == nullptr || !head_->next)
            {
                return true;
            }

            Node *sorted_head = nullptr;

            NodePtr current = std::move(head_);

            while (current)
            {
                NodePtr next_node = std::move(current->next);

                if (!sorted_head || current->value < sorted_head->value)
                {
                    current->next = sorted_head;
                    sorted_head = current.release();
                }
                else
                {
                    Node *trailer = sorted_head.get();

                    while (trailer->next && trailer->next->value < current->value)
                    {
                        trailer = trailer->next.get();
                    }

                    current->next = trailer->next;
                    trailer->next = current.release();
                }

                current = std::move(next_node);
            }

            head_.reset(sorted_head);

            return true; */
        }
    };
} // namespace ragc

#endif
