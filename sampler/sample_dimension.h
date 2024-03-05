#pragma once
#include <iostream>

enum struct SampleDimension : uint32_t {
  ePixelX,
  ePixelY,
  eLightId,
  eLightPointX,
  eLightPointY,
  eBSDF0,
  eBSDF1,
  eBSDF2,
  eBSDF3,
  eRussianRoulette,
  eNUM_DIMENSIONS
};
