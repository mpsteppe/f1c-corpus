int __thiscall CleanupWrapper(void *this)
{
  AIStateBufferInitialize(&byte_7C56C0);
  return StringCopyWithBufferRealloc((int)this + 8, byte_5EA438);
}

