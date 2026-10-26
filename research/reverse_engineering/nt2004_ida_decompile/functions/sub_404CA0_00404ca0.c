int __thiscall sub_404CA0(int this)
{
  int result; // eax
  int v3; // ecx
  void *v4; // ebp
  char *v5; // esi
  int v6; // ecx
  int v7; // ebx

  if ( *(_DWORD *)(this + 388) )
    sub_5BE8AE(*(LPVOID *)(this + 388));
  if ( *(_DWORD *)(this + 392) )
    sub_5BE8AE(*(LPVOID *)(this + 392));
  if ( *(_DWORD *)(this + 396) )
    sub_5BE8AE(*(LPVOID *)(this + 396));
  if ( *(_DWORD *)(this + 400) )
    sub_5BE8AE(*(LPVOID *)(this + 400));
  result = *(_DWORD *)(this + 360);
  *(_DWORD *)(this + 388) = 0;
  *(_DWORD *)(this + 392) = 0;
  *(_DWORD *)(this + 396) = 0;
  *(_DWORD *)(this + 400) = 0;
  if ( result )
  {
    v3 = *(_DWORD *)(result - 4);
    v4 = (void *)(result - 4);
    v5 = (char *)(result + 348 * v3);
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 348;
        nullsub_6(v5);
        --v7;
      }
      while ( v7 );
    }
    result = sub_5BE8AE(v4);
  }
  *(_DWORD *)(this + 360) = 0;
  *(_DWORD *)(this + 364) = 0;
  *(_DWORD *)(this + 356) = 0;
  *(_DWORD *)(this + 380) = -1082130432;
  return result;
}
