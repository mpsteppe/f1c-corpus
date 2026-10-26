int __thiscall sub_5C3E40(int *this, int a2)
{
  _DWORD *v3; // edi
  int result; // eax
  int v5; // ebx
  int v6; // esi
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h] BYREF

  v3 = this + 1;
  result = 0;
  v5 = 0;
  v7 = 0;
  if ( this[1] > 0 )
  {
    do
    {
      v6 = *(_DWORD *)(this[3] + 4 * v5);
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 16))(v6) == a2 )
      {
        v8 = v6;
        sub_5D15B0(this + 1, &v8);
        (**(void (__thiscall ***)(int, int))v6)(v6, 1);
        ++v7;
      }
      else
      {
        ++v5;
      }
    }
    while ( v5 < *v3 );
    return v7;
  }
  return result;
}
