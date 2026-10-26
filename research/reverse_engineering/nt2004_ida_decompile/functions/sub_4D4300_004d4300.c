int __stdcall sub_4D4300(int a1, void *a2, int a3)
{
  int result; // eax
  unsigned __int8 Buffer; // [esp+Bh] [ebp-1h] BYREF

  Buffer = 0;
  sub_57A3D0(&Buffer, 1u);
  result = sub_57A3D0(a2, Buffer);
  *((_BYTE *)a2 + Buffer) = 0;
  return result;
}
