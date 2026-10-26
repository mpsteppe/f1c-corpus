int __usercall sub_6B88CC@<eax>(int result@<eax>, __int16 a2@<dx>)
{
  *(_BYTE *)(*(_DWORD *)(result + 8) + (*(_DWORD *)(result + 20))++) = HIBYTE(a2);
  *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = a2;
  ++*(_DWORD *)(result + 20);
  return result;
}
