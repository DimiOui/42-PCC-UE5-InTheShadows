cmake_minimum_required(VERSION 3.7)
add_library(UE4Library STATIC 
instantiations_UE4Library.h
instantiations_UE4Library.cpp
UE4Library/StringRange.Pregenerated.cpp
UE4Library/StringRange.Pregenerated.h
UE4Library/PlayState.Pregenerated.cpp
UE4Library/PlayState.Pregenerated.h
UE4Library/RequestResultBase.Pregenerated.cpp
UE4Library/RequestResultBase.Pregenerated.h
UE4Library/RequestSucceed.Pregenerated.cpp
UE4Library/RequestSucceed.Pregenerated.h
UE4Library/RequestFailed.Pregenerated.cpp
UE4Library/RequestFailed.Pregenerated.h
UE4Library/LogMessageInfo.Pregenerated.cpp
UE4Library/LogMessageInfo.Pregenerated.h
UE4Library/UnrealLogEvent.Pregenerated.cpp
UE4Library/UnrealLogEvent.Pregenerated.h
UE4Library/UClass.Pregenerated.cpp
UE4Library/UClass.Pregenerated.h
UE4Library/BlueprintFunction.Pregenerated.cpp
UE4Library/BlueprintFunction.Pregenerated.h
UE4Library/ScriptCallStackFrame.Pregenerated.cpp
UE4Library/ScriptCallStackFrame.Pregenerated.h
UE4Library/IScriptCallStack.Pregenerated.cpp
UE4Library/IScriptCallStack.Pregenerated.h
UE4Library/EmptyScriptCallStack.Pregenerated.cpp
UE4Library/EmptyScriptCallStack.Pregenerated.h
UE4Library/ScriptCallStack.Pregenerated.cpp
UE4Library/ScriptCallStack.Pregenerated.h
UE4Library/UnableToDisplayScriptCallStack.Pregenerated.cpp
UE4Library/UnableToDisplayScriptCallStack.Pregenerated.h
UE4Library/IScriptMsg.Pregenerated.cpp
UE4Library/IScriptMsg.Pregenerated.h
UE4Library/ScriptMsgException.Pregenerated.cpp
UE4Library/ScriptMsgException.Pregenerated.h
UE4Library/ScriptMsgCallStack.Pregenerated.cpp
UE4Library/ScriptMsgCallStack.Pregenerated.h
UE4Library/BlueprintHighlighter.Pregenerated.cpp
UE4Library/BlueprintHighlighter.Pregenerated.h
UE4Library/BlueprintReference.Pregenerated.cpp
UE4Library/BlueprintReference.Pregenerated.h
UE4Library/ConnectionInfo.Pregenerated.cpp
UE4Library/ConnectionInfo.Pregenerated.h
UE4Library/NotificationType.Pregenerated.cpp
UE4Library/NotificationType.Pregenerated.h
UE4Library/UE4Library.Pregenerated.cpp
UE4Library/UE4Library.Pregenerated.h
UE4Library/RequestResultBase_Unknown.Pregenerated.cpp
UE4Library/RequestResultBase_Unknown.Pregenerated.h
UE4Library/IScriptCallStack_Unknown.Pregenerated.cpp
UE4Library/IScriptCallStack_Unknown.Pregenerated.h
UE4Library/IScriptMsg_Unknown.Pregenerated.cpp
UE4Library/IScriptMsg_Unknown.Pregenerated.h)
target_include_directories(UE4Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(UE4Library PUBLIC rd_framework_cpp)
