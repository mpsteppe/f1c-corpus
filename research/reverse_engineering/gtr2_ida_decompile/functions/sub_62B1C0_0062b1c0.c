int __usercall sub_62B1C0@<eax>(int result@<eax>, __int16 a2@<cx>)
{
  int v2; // esi
  int v3; // edx

  *(_BYTE *)(*(_DWORD *)(result + 8) + *(_DWORD *)(result + 20)) = HIBYTE(a2);
  v2 = *(_DWORD *)(result + 8);
  v3 = *(_DWORD *)(result + 20) + 1;
  *(_DWORD *)(result + 20) = v3;
  *(_BYTE *)(v3 + v2) = a2;
  ++*(_DWORD *)(result + 20);
  return result;
}
