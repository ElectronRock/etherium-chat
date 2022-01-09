/*
 * Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 */

#pragma once

// useful macro section

 /**
  * \brief Explicitly deletes move - assign operator and move constructor
  * \param Name Class name to be declared not move constructable
  */
#define DECLARE_NON_MOVABLE(Name) Name ( Name &&) = delete; \
    Name & operator=( Name &&) = delete

 /**
  * \brief Explicitly deletes copy - assign operator and copy constructor
  * \param Name Class name to be declared not copy constructable
  */
#define DECLARE_NON_COPYABLE(Name) Name(const Name &) = delete; \
    Name & operator=(const Name &) = delete

 /**
  * \brief Explicitly declares default move - constructor and move - assign operator
  * \param Name Class name to be declared
  */
#define DECLARE_EXPLICIT_DEFAULT_MOVABLE(Name) Name ( Name &&) = default; \
    Name & operator=( Name &&) = default

  /**
   * \brief Explicitly declares default copy - constructor and copy - assign operator
   * \param Name Class name to be declared
   */
#define DECLARE_EXPLICIT_DEFAULT_COPYABLE(Name) Name ( const Name &) = default; \
    Name & operator=( const Name &) = default
