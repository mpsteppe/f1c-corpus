int __thiscall sub_472690(_DWORD *this)
{
  int v2; // ecx
  _DWORD *v3; // eax
  char *v4; // eax
  int v5; // ecx
  _DWORD *v6; // eax
  char *v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax
  char *v10; // eax
  int v11; // ecx
  _DWORD *v12; // eax
  char *v13; // eax
  int v15; // [esp+8h] [ebp-8h] BYREF
  int v16; // [esp+Ch] [ebp-4h] BYREF

  v16 = 0;
  v15 = 0;
  sub_4AE870(&v16, &v15);
  if ( !(*(int (__thiscall **)(_DWORD *, int, int))(*this + 20))(this, v16, v15) )
    this[104] = -1;
  v2 = this[110];
  if ( v2 != this[105] )
  {
    if ( v2 >= 0 && v2 < this[74] )
    {
      v3 = (_DWORD *)this[71];
      if ( v2 <= 0 )
      {
LABEL_9:
        if ( v3 && *v3 )
        {
          v4 = (char *)sub_49C9C0(this);
          sub_4A5A60(v4);
        }
      }
      else
      {
        while ( v3 )
        {
          v3 = (_DWORD *)v3[1];
          if ( --v2 <= 0 )
            goto LABEL_9;
        }
      }
    }
    v5 = this[105];
    this[110] = v5;
    if ( v5 >= 0 && v5 < this[74] )
    {
      v6 = (_DWORD *)this[71];
      if ( v5 <= 0 )
      {
LABEL_17:
        if ( v6 && *v6 )
        {
          v7 = (char *)sub_49CA00(this);
          sub_4A5A60(v7);
        }
      }
      else
      {
        while ( v6 )
        {
          v6 = (_DWORD *)v6[1];
          if ( --v5 <= 0 )
            goto LABEL_17;
        }
      }
    }
  }
  v8 = this[109];
  if ( v8 != this[110] && v8 >= 0 && v8 < this[74] )
  {
    v9 = (_DWORD *)this[71];
    if ( v8 <= 0 )
    {
LABEL_26:
      if ( v9 && *v9 )
      {
        v10 = (char *)sub_49C9C0(this);
        sub_4A5A60(v10);
      }
    }
    else
    {
      while ( v9 )
      {
        v9 = (_DWORD *)v9[1];
        if ( --v8 <= 0 )
          goto LABEL_26;
      }
    }
  }
  v11 = this[104];
  this[109] = v11;
  if ( v11 >= 0 && v11 < this[74] )
  {
    v12 = (_DWORD *)this[71];
    if ( v11 <= 0 )
    {
LABEL_34:
      if ( v12 && *v12 && (unsigned __int8)sub_4A4680(v16, v15) )
      {
        v13 = (char *)sub_49C9E0(this);
        sub_4A5A60(v13);
      }
    }
    else
    {
      while ( v12 )
      {
        v12 = (_DWORD *)v12[1];
        if ( --v11 <= 0 )
          goto LABEL_34;
      }
    }
  }
  return 0;
}
