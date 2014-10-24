//AUTOMATICALLY GENERATED - DO NOT EDIT

#ifndef METCollection_H
#define  METCollection_H

#include <string>
#include <vector>

// albers specific includes
#include "albers/Registry.h"
#include "albers/CollectionBase.h"

// datamodel specific includes
#include "MET.h"
#include "METHandle.h"

typedef std::vector<MET> METVector;
typedef std::vector<METHandle> METHandleVector;

class METCollectionIterator {

  public:
    METCollectionIterator(int index, const METCollection* collection) : m_index(index), m_collection(collection) {}

    bool operator!=(const METCollectionIterator& x) const {
      return m_index != x.m_index; //TODO: may not be complete
    }

    const METHandle operator*() const;

    const METCollectionIterator& operator++() const {
      ++m_index;
      return *this;
    }

  private:
    mutable int m_index;
    const METCollection* m_collection;
};

/**
A Collection is identified by an ID.
*/

class METCollection : public albers::CollectionBase {

public:
  typedef const METCollectionIterator const_iterator;

  METCollection();
//  METCollection(METVector* data, int collectionID);
  ~METCollection(){};

  void clear();
  /// Append a new object to the collection, and return a Handle to this object.
  METHandle& create();

  /// Returns a Handle to the object at position index in the collection
  const METHandle& get(int index) const;

  /// Currently does nothing
  void prepareForWrite(const albers::Registry* registry);
  void prepareAfterRead(albers::Registry* registry);
  void setPODsAddress(const void* address);

  void setID(unsigned ID){m_collectionID = ID;};

  // support for the iterator protocol
  const const_iterator begin() const {
    return const_iterator(0, this);
  }
  const	const_iterator end() const {
    return const_iterator(m_handles.size(), this);
  }

  /// returns the address of the pointer to the data buffer
  void* _getRawBuffer() { return (void*)&m_data;};

  /// returns the pointer to the data buffer
  std::vector<MET>* _getBuffer() { return m_data;};

  /// returns the vector of Handles
  const METHandleVector& getHandles() { return m_handles; }

  /// print some information
  void print() const;

private:
  unsigned m_collectionID;
  METVector* m_data;
  METHandleVector m_handles;

};

#endif