﻿#pragma once

#define ESP_RESOURCE_MONITOR_VERSION_MAJOR 1
#define ESP_RESOURCE_MONITOR_VERSION_MINOR 0
#define ESP_RESOURCE_MONITOR_VERSION_PATCH 0
#define _STRINGIFY(x)                      #x
#define STRINGIFY(x)                       _STRINGIFY(x)

#define ESP_RESOURCE_MONITOR_VERSION \
  STRINGIFY(ESP_RESOURCE_MONITOR_VERSION_MAJOR) "." STRINGIFY(ESP_RESOURCE_MONITOR_VERSION_MINOR) "." STRINGIFY(ESP_RESOURCE_MONITOR_VERSION_PATCH)

#define ESP_RESOURCE_MONITOR_VERSION_FULL "v" ESP_RESOURCE_MONITOR_VERSION
