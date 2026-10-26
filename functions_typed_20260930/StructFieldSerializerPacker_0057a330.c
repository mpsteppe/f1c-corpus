const void **__thiscall sub_57A330(int this, int a2, _DWORD *a3)
{
  int v3; // ebx
  const void **result; // eax

  v3 = a2;
  MemcpyWithAdvancePointer((const void **)&a2, (void *)(this + 4), 4u);
  MemcpyWithAdvancePointer((const void **)&a2, (void *)(this + 8), 0x20u);
  MemcpyWithAdvancePointer((const void **)&a2, (void *)(this + 40), 1u);
  MemcpyWithAdvancePointer((const void **)&a2, (void *)(this + 41), 1u);
  MemcpyWithAdvancePointer((const void **)&a2, (void *)(this + 42), 1u);
  MemcpyWithAdvancePointer((const void **)&a2, (void *)(this + 43), 1u);
  MemcpyWithAdvancePointer((const void **)&a2, (void *)(this + 44), 1u);
  result = MemcpyWithAdvancePointer((const void **)&a2, (void *)(this + 45), *(unsigned __int8 *)(this + 44));
  *a3 = a2 - v3;
  return result;
}

