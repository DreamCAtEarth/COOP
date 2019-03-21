#pragma once

#define newObject(...) newObject(&(overrideConstructorObject) { .sentinel = 0, __VA_ARGS__ })