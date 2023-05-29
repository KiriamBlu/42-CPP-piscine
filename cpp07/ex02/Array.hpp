
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
    T* arr;
    unsigned int size;

public:
    Array() : arr(new T[0]), size(0) {}

    Array(unsigned int number) : arr(new T[number]), size(number) {}

    Array(const Array<T>& tmp) : arr(nullptr), size(0) {
        *this = tmp;
    }

    ~Array() {
        delete[] arr;
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = new T[size];
            for (unsigned int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    T& operator[](unsigned int index) {
        if (index >= size || index < 0)
            throw std::runtime_error("Index out of range");
        return arr[index];
    }
};

#endif
