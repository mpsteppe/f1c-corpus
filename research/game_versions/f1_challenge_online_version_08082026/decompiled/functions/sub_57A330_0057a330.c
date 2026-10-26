const void **__thiscall sub_57A330(int this, int a2, _DWORD *a3)
{
  int v3; // ebx
  const void **result; // eax

  v3 = a2;
  sub_57A1B0((const void **)&a2, (void *)(this + 4), 4u);
  sub_57A1B0((const void **)&a2, (void *)(this + 8), 0x20u);
  sub_57A1B0((const void **)&a2, (void *)(this + 40), 1u);
  sub_57A1B0((const void **)&a2, (void *)(this + 41), 1u);
  sub_57A1B0((const void **)&a2, (void *)(this + 42), 1u);
  sub_57A1B0((const void **)&a2, (void *)(this + 43), 1u);
  sub_57A1B0((const void **)&a2, (void *)(this + 44), 1u);
  result = sub_57A1B0((const void **)&a2, (void *)(this + 45), *(unsigned __int8 *)(this + 44));
  *a3 = a2 - v3;
  return result;
}
