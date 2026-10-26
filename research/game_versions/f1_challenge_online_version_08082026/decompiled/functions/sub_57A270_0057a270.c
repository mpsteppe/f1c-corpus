void **__thiscall sub_57A270(int this, int a2, int a3, _DWORD *a4)
{
  int v4; // ebx
  void **result; // eax

  v4 = a2;
  sub_57A180((void **)&a2, (const void *)(this + 4), 4u);
  sub_57A180((void **)&a2, (const void *)(this + 8), 0x20u);
  sub_57A180((void **)&a2, (const void *)(this + 40), 1u);
  sub_57A180((void **)&a2, (const void *)(this + 41), 1u);
  sub_57A180((void **)&a2, (const void *)(this + 42), 1u);
  sub_57A180((void **)&a2, (const void *)(this + 43), 1u);
  sub_57A180((void **)&a2, (const void *)(this + 44), 1u);
  result = sub_57A180((void **)&a2, (const void *)(this + 45), *(unsigned __int8 *)(this + 44));
  *a4 = a2 - v4;
  return result;
}
