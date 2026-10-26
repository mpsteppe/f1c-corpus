int __cdecl operator new(size_t Size)
{
  return _nh_malloc(Size, 1);
}
