/*=========================================================================
 *
 *  Copyright David Doria 2011 daviddoria@gmail.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

// STL
#include <algorithm> // nth_element()
#include <fstream>
#include <iostream>
#include <limits>

namespace Helpers
{

template <class T>
bool IsNaN(const T a)
{
  return a != a;
}

template <class T>
bool ContainsNaN(const T a)
{
  for(unsigned int i = 0; i < a.size(); ++i)
  {
    if(IsNaN(a[i]))
    {
      return true;
    }
  }
  return false;
}

template <class T>
unsigned int argmin(const T& vec)
{
  typename T::value_type minValue = std::numeric_limits<typename T::value_type>::max();
  unsigned int minLocation = 0;
  for(unsigned int i = 0; i < vec.size(); ++i)
    {
    if(vec[i] < minValue)
      {
      minValue = vec[i];
      minLocation = i;
      }
    }

  return minLocation;
}


template<typename T>
void NormalizeVector(std::vector<T>& v)
{
  T total = static_cast<T>(0);
  for(unsigned int i = 0; i < v.size(); ++i)
    {
    total += v[i];
    }

  for(unsigned int i = 0; i < v.size(); ++i)
    {
    v[i] /= total;
    }
}


template<typename T>
typename T::value_type VectorMedian(T v)
{
  // Don't want to pass by reference because the elements are shuffled around.

  int n = v.size() / 2;
  std::nth_element(v.begin(), v.begin()+n, v.end());
  return v[n];
}

template<typename TTo, typename TFrom>
TTo ConvertFrom(const TFrom& object)
{
  TTo t;
  t[0] = object[0];
  t[1] = object[1];
  return t;
}

template<typename TForwardIterator>
float Sum(const TForwardIterator first, const TForwardIterator last)
{
  float sum = 0.0f;
  for(TForwardIterator iter = first; iter != last; ++iter)
  {
    sum += *iter;
  }

  return sum;
}

template<typename TVector>
float VectorSumOfAbsoluteDifferences(const TVector& a, const TVector& b)
{
  assert(a.size() == b.size());

  float sum = 0.0f;
  for(unsigned int i = 0; i < a.size(); ++i)
  {
    sum += fabs(a[i] - b[i]);
  }

  return sum;
}

template<typename TNode>
void OutputNode(const TNode& a)
{
  std::cout << "(" << a[0] << ", " << a[1] << ")" << std::endl;
}

template<typename T>
void WriteVectorToFile(const std::vector<T> &v, const std::string& filename)
{
  std::ofstream fout(filename.c_str());

  for(unsigned int i = 0; i < v.size(); ++i)
    {
    fout << v[i] << std::endl;
    }

  fout.close();
}

template <typename T>
void OutputFirst(const T& vec)
{
  for(unsigned int i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i].first << " ";
  }
  std::cout << std::endl;
}

template <typename TPair>
bool SortByFirstAccending(TPair object1, TPair object2)
{
  return object1.first < object2.first;
}

template <typename TPair>
bool SortBySecondAccending(TPair object1, TPair object2)
{
  return object1.second < object2.second;
}

template <typename T>
bool Contains(const std::vector<T>& vec, const T& value)
{
  for(unsigned int i = 0; i < vec.size(); ++i)
  {
    if(vec[i] == value)
    {
      return true;
    }
  }
  return false;
}

template <typename T>
void Output(const std::vector<T>& vec)
{
  for(unsigned int i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T1, typename T2>
std::vector<T1> ExtractFirst(const std::vector<std::pair<T1, T2> >& vec)
{
  std::vector<T1> firsts(vec.size());
  for(size_t i = 0; i < vec.size(); ++i)
  {
    firsts[i] = vec[i].first;
  }
  return firsts;
}

template <typename T>
unsigned int ClosestIndex(const std::vector<T>& vec, const T& value)
{
  std::vector<float> distances(vec.size());
  for(size_t i = 0; i < vec.size(); ++i)
  {
    distances[i] = fabs(vec[i] - value);
  }

  return argmin(distances);
}

template <class T>
unsigned int min(const T& v)
{
  auto minmax = std::minmax_element(v.begin(), v.end());

  return *(minmax.first);
}

template <class T>
unsigned int max(const T& v)
{
  auto minmax = std::minmax_element(v.begin(), v.end());

  return *(minmax.second);
}

template <class T>
bool DoesQueueContain(std::queue<T> q, const T& value)
{
  while(!q.empty())
  {
    T element = q.front();
    if(element == value)
    {
      return true;
    }
    q.pop();
  }

  return false;
}

template <class T>
bool DoesStackContain(std::stack<T> s, const T& value)
{
  while(!s.empty())
  {
    T element = s.top();
    if(element == value)
    {
      return true;
    }
    s.pop();
  }

  return false;
}

}// end namespace
