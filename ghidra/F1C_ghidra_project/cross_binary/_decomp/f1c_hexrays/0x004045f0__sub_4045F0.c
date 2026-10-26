// f1c  0x004045f0  size=178
int __thiscall sub_4045F0(int this)
{
  int result; // eax
  int v3; // ecx
  void *v4; // ebp
  int v5; // esi
  int v6; // ecx
  int v7; // ebx

  if ( *(_DWORD *)(this + 336) )
    sub_587BCF(*(LPVOID *)(this + 336));
  if ( *(_DWORD *)(this + 340) )
    sub_587BCF(*(LPVOID *)(this + 340));
  if ( *(_DWORD *)(this + 344) )
    sub_587BCF(*(LPVOID *)(this + 344));
  result = *(_DWORD *)(this + 308);
  *(_DWORD *)(this + 336) = 0;
  *(_DWORD *)(this + 340) = 0;
  *(_DWORD *)(this + 344) = 0;
  *(_DWORD *)(this + 328) = -1082130432;
  if ( result )
  {
    v3 = *(_DWORD *)(result - 4);
    v4 = (void *)(result - 4);
    v5 = result + 316 * v3;
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 316;
        nullsub_3(v5);
        --v7;
      }
      while ( v7 );
    }
    result = sub_587BCF(v4);
  }
  *(_DWORD *)(this + 308) = 0;
  *(_DWORD *)(this + 312) = 0;
  *(_DWORD *)(this + 304) = 0;
  return result;
}
