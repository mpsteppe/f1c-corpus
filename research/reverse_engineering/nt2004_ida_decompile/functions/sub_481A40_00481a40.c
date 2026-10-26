int __thiscall sub_481A40(_DWORD *this)
{
  char *v2; // eax
  int v3; // edi
  int v5; // [esp+8h] [ebp-28h] BYREF
  int v6; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v7[3]; // [esp+10h] [ebp-20h] BYREF
  int v8; // [esp+1Ch] [ebp-14h]
  int v9; // [esp+20h] [ebp-10h]
  int v10; // [esp+24h] [ebp-Ch]
  int v11; // [esp+28h] [ebp-8h]
  int v12; // [esp+2Ch] [ebp-4h]

  if ( sub_49D1E0(this) != 5 )
    return sub_46FB40(this);
  v6 = 0;
  v5 = 0;
  v2 = (char *)sub_49D1F0(0);
  if ( v2 )
  {
    v3 = sub_4AD520(v2);
    if ( v3 )
    {
      sub_4AE870(&v6, &v5);
      if ( !(*(int (__thiscall **)(_DWORD *, int, int))(*this + 20))(this, v6, v5)
        && !(*(int (__thiscall **)(int, int, int))(*(_DWORD *)v3 + 20))(v3, v6, v5) )
      {
        v11 = 0;
        v10 = 0;
        v9 = 0;
        v8 = 0;
        memset(v7, 0, sizeof(v7));
        v12 = 0;
        sub_4AE8B0(v7);
        if ( v8 )
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 40))(v3, 0);
          this[207] = 0;
        }
      }
    }
  }
  return (*(int (__thiscall **)(_DWORD *))(*this + 164))(this);
}
