// Copyright (c) 2011 The WebM project authors. All Rights Reserved.
//
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file in the root of the source
// tree. An additional intellectual property rights grant can be found
// in the file PATENTS.  All contributing project authors may
// be found in the AUTHORS file in the root of the source tree.

#include "mkvwriter.hpp"

#ifdef _MSC_VER
#include <share.h> // for _SH_DENYWR
#endif

#include <cassert>
#include <new>

namespace mkvmuxer {

MkvWriter::MkvWriter() : file_(NULL) {
}

MkvWriter::~MkvWriter() {
  Close();
}

int32 MkvWriter::Write(const void* buffer, uint32 length) {
  assert(file_);

  if (length == 0)
    return 0;

  if (buffer == NULL)
    return -1;

  const size_t bytes_written = fwrite(buffer, 1, length, file_);

  return (bytes_written == length) ? 0 : -1;
}

bool MkvWriter::Open(const char* filename) {
  if (filename == NULL)
    return false;

  if (file_)
    return false;

#ifdef _MSC_VER
  file_ = _fsopen(filename, "wb", _SH_DENYWR);
#else
  file_ = fopen(filename, "wb");
#endif
  if (file_ == NULL)
    return false;
  return true;
}

void MkvWriter::Close() {
  if (file_) {
    fclose(file_);
    file_ = NULL;
  }
}

int64 MkvWriter::Position() const {
  assert(file_);
#ifdef _MSC_VER
    return _ftelli64(file_);
#else
    return ftell(file_);
#endif
}

int32 MkvWriter::Position(int64 position) {
  assert(file_);
#ifdef _MSC_VER
    return _fseeki64(file_, position, SEEK_SET);
#else
    return fseek(file_, position, SEEK_SET);
#endif
}

bool MkvWriter::Seekable() const {
  return true;
}

}  // namespace mkvmuxer