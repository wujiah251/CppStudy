// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: simple.proto

#include "simple.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Simple {
constexpr EchoRequest::EchoRequest(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : msg_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct EchoRequestDefaultTypeInternal {
  constexpr EchoRequestDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~EchoRequestDefaultTypeInternal() {}
  union {
    EchoRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT EchoRequestDefaultTypeInternal _EchoRequest_default_instance_;
constexpr EchoResponse::EchoResponse(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : msg_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct EchoResponseDefaultTypeInternal {
  constexpr EchoResponseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~EchoResponseDefaultTypeInternal() {}
  union {
    EchoResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT EchoResponseDefaultTypeInternal _EchoResponse_default_instance_;
}  // namespace Simple
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_simple_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_simple_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_simple_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_simple_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Simple::EchoRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Simple::EchoRequest, msg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Simple::EchoResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Simple::EchoResponse, msg_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Simple::EchoRequest)},
  { 7, -1, -1, sizeof(::Simple::EchoResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Simple::_EchoRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Simple::_EchoResponse_default_instance_),
};

const char descriptor_table_protodef_simple_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014simple.proto\022\006Simple\"\032\n\013EchoRequest\022\013\n"
  "\003msg\030\001 \001(\t\"\033\n\014EchoResponse\022\013\n\003msg\030\001 \001(\t2"
  "=\n\006Server\0223\n\004Echo\022\023.Simple.EchoRequest\032\024"
  ".Simple.EchoResponse\"\000b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_simple_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_simple_2eproto = {
  false, false, 150, descriptor_table_protodef_simple_2eproto, "simple.proto", 
  &descriptor_table_simple_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_simple_2eproto::offsets,
  file_level_metadata_simple_2eproto, file_level_enum_descriptors_simple_2eproto, file_level_service_descriptors_simple_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_simple_2eproto_getter() {
  return &descriptor_table_simple_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_simple_2eproto(&descriptor_table_simple_2eproto);
namespace Simple {

// ===================================================================

class EchoRequest::_Internal {
 public:
};

EchoRequest::EchoRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Simple.EchoRequest)
}
EchoRequest::EchoRequest(const EchoRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_msg().empty()) {
    msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_msg(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:Simple.EchoRequest)
}

void EchoRequest::SharedCtor() {
msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

EchoRequest::~EchoRequest() {
  // @@protoc_insertion_point(destructor:Simple.EchoRequest)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void EchoRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  msg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void EchoRequest::ArenaDtor(void* object) {
  EchoRequest* _this = reinterpret_cast< EchoRequest* >(object);
  (void)_this;
}
void EchoRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void EchoRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void EchoRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:Simple.EchoRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  msg_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* EchoRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string msg = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_msg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Simple.EchoRequest.msg"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* EchoRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Simple.EchoRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string msg = 1;
  if (!this->_internal_msg().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_msg().data(), static_cast<int>(this->_internal_msg().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Simple.EchoRequest.msg");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Simple.EchoRequest)
  return target;
}

size_t EchoRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Simple.EchoRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string msg = 1;
  if (!this->_internal_msg().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_msg());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData EchoRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    EchoRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*EchoRequest::GetClassData() const { return &_class_data_; }

void EchoRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<EchoRequest *>(to)->MergeFrom(
      static_cast<const EchoRequest &>(from));
}


void EchoRequest::MergeFrom(const EchoRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Simple.EchoRequest)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_msg().empty()) {
    _internal_set_msg(from._internal_msg());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void EchoRequest::CopyFrom(const EchoRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Simple.EchoRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EchoRequest::IsInitialized() const {
  return true;
}

void EchoRequest::InternalSwap(EchoRequest* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &msg_, lhs_arena,
      &other->msg_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata EchoRequest::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_simple_2eproto_getter, &descriptor_table_simple_2eproto_once,
      file_level_metadata_simple_2eproto[0]);
}

// ===================================================================

class EchoResponse::_Internal {
 public:
};

EchoResponse::EchoResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Simple.EchoResponse)
}
EchoResponse::EchoResponse(const EchoResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_msg().empty()) {
    msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_msg(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:Simple.EchoResponse)
}

void EchoResponse::SharedCtor() {
msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

EchoResponse::~EchoResponse() {
  // @@protoc_insertion_point(destructor:Simple.EchoResponse)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void EchoResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  msg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void EchoResponse::ArenaDtor(void* object) {
  EchoResponse* _this = reinterpret_cast< EchoResponse* >(object);
  (void)_this;
}
void EchoResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void EchoResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void EchoResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:Simple.EchoResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  msg_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* EchoResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string msg = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_msg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Simple.EchoResponse.msg"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* EchoResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Simple.EchoResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string msg = 1;
  if (!this->_internal_msg().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_msg().data(), static_cast<int>(this->_internal_msg().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Simple.EchoResponse.msg");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Simple.EchoResponse)
  return target;
}

size_t EchoResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Simple.EchoResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string msg = 1;
  if (!this->_internal_msg().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_msg());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData EchoResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    EchoResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*EchoResponse::GetClassData() const { return &_class_data_; }

void EchoResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<EchoResponse *>(to)->MergeFrom(
      static_cast<const EchoResponse &>(from));
}


void EchoResponse::MergeFrom(const EchoResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Simple.EchoResponse)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_msg().empty()) {
    _internal_set_msg(from._internal_msg());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void EchoResponse::CopyFrom(const EchoResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Simple.EchoResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EchoResponse::IsInitialized() const {
  return true;
}

void EchoResponse::InternalSwap(EchoResponse* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &msg_, lhs_arena,
      &other->msg_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata EchoResponse::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_simple_2eproto_getter, &descriptor_table_simple_2eproto_once,
      file_level_metadata_simple_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Simple
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Simple::EchoRequest* Arena::CreateMaybeMessage< ::Simple::EchoRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Simple::EchoRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::Simple::EchoResponse* Arena::CreateMaybeMessage< ::Simple::EchoResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Simple::EchoResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
