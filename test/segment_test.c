#include <cwalk.h>
#include <memory.h>
#include <stdlib.h>

int segment_type()
{
  const char *path;
  struct cwk_segment segment;

  path = "/a/./../.folder/..folder";

  if (!cwk_path_get_first_segment(path, &segment)) {
    return EXIT_FAILURE;
  }

  if (cwk_path_get_segment_type(&segment) != CWK_NORMAL) {
    return EXIT_FAILURE;
  }

  if (!cwk_path_get_next_segment(&segment)) {
    return EXIT_FAILURE;
  }

  if (cwk_path_get_segment_type(&segment) != CWK_CURRENT) {
    return EXIT_FAILURE;
  }

  if (!cwk_path_get_next_segment(&segment)) {
    return EXIT_FAILURE;
  }

  if (cwk_path_get_segment_type(&segment) != CWK_BACK) {
    return EXIT_FAILURE;
  }

  if (!cwk_path_get_next_segment(&segment)) {
    return EXIT_FAILURE;
  }

  if (cwk_path_get_segment_type(&segment) != CWK_NORMAL) {
    return EXIT_FAILURE;
  }

  if (!cwk_path_get_next_segment(&segment)) {
    return EXIT_FAILURE;
  }

  if (cwk_path_get_segment_type(&segment) != CWK_NORMAL) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int segment_previous()
{
  const char *path;
  struct cwk_segment segment;

  path = "/now/hello_world/abc/";

  if (!cwk_path_get_last_segment(path, &segment)) {
    return EXIT_FAILURE;
  }

  if (strncmp(segment.begin, "abc", segment.size) != 0) {
    return EXIT_FAILURE;
  }

  if (!cwk_path_get_previous_segment(&segment)) {
    return EXIT_FAILURE;
  }

  if (strncmp(segment.begin, "hello_world", segment.size) != 0) {
    return EXIT_FAILURE;
  }

  if (!cwk_path_get_previous_segment(&segment)) {
    return EXIT_FAILURE;
  }

  if (strncmp(segment.begin, "now", segment.size) != 0) {
    return EXIT_FAILURE;
  }

  if (cwk_path_get_previous_segment(&segment)) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int segment_next()
{
  const char *path;
  struct cwk_segment segment;

  path = "/hello_world/abc/";

  if (!cwk_path_get_first_segment(path, &segment)) {
    return EXIT_FAILURE;
  }

  if (strncmp(segment.begin, "hello_world", segment.size) != 0) {
    return EXIT_FAILURE;
  }

  if (!cwk_path_get_next_segment(&segment)) {
    return EXIT_FAILURE;
  }

  if (strncmp(segment.begin, "abc", segment.size) != 0) {
    return EXIT_FAILURE;
  }

  if (cwk_path_get_next_segment(&segment)) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int segment_last()
{
  const char *path;
  struct cwk_segment segment;

  path = "/hello_world/abc";

  if (!cwk_path_get_last_segment(path, &segment)) {
    return EXIT_FAILURE;
  }

  if (strncmp(segment.begin, "abc", segment.size) != 0) {
    return EXIT_FAILURE;
  }

  path = "hello_world/abc";

  if (!cwk_path_get_last_segment(path, &segment)) {
    return EXIT_FAILURE;
  }

  if (strncmp(segment.begin, "abc", segment.size) != 0) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int segment_first()
{
  const char *path;
  struct cwk_segment segment;

  path = "/hello_world/abc";

  if (!cwk_path_get_first_segment(path, &segment)) {
    return EXIT_FAILURE;
  }

  if (strncmp(segment.begin, "hello_world", segment.size) != 0) {
    return EXIT_FAILURE;
  }

  path = "hello_world/abc";

  if (!cwk_path_get_first_segment(path, &segment)) {
    return EXIT_FAILURE;
  }

  if (strncmp(segment.begin, "hello_world", segment.size) != 0) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}