int __thiscall sub_4A08E0(int *this)
{
  int v2; // edx
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // ecx
  CHAR *v10; // eax
  CHAR *v11; // edi
  CHAR *v12; // edx
  CHAR *v13; // ecx
  int v15; // [esp+8h] [ebp-8h] BYREF
  int v16; // [esp+Ch] [ebp-4h] BYREF

  sub_4AE870(&v16, &v15);
  v2 = *this;
  *((_BYTE *)this + 368) = 0;
  *((_BYTE *)this + 369) = 0;
  *((_BYTE *)this + 370) = 0;
  if ( (*(int (__thiscall **)(int *))(v2 + 12))(this) <= 0 )
    v3 = (*(int (__thiscall **)(int *))(*this + 12))(this);
  else
    v3 = this[4];
  v4 = (*(int (__thiscall **)(int *))(*this + 4))(this);
  if ( v16 <= v4 || v16 > v3 )
  {
    if ( !*((_BYTE *)this + 268) )
    {
      (*(void (__thiscall **)(int *, _DWORD))(*this + 44))(this, 0);
      return -1;
    }
    if ( this[97] )
    {
      v8 = sub_4A0140(this, v15);
      v9 = (_DWORD *)this[36];
      this[101] = v8;
      if ( v8 <= 0 )
      {
LABEL_21:
        if ( v9 )
        {
          v10 = (CHAR *)v9[70];
          if ( !v10 )
            v10 = &byte_629120;
          v11 = (CHAR *)v9[68];
          if ( !v11 )
            v11 = &byte_629120;
          v12 = (CHAR *)v9[42];
          if ( !v12 )
            v12 = &byte_629120;
          v13 = (CHAR *)v9[40];
          if ( !v13 )
            v13 = &byte_629120;
          (*(void (__thiscall **)(int *, CHAR *, CHAR *, CHAR *, CHAR *))(*this + 168))(this, v13, v12, v11, v10);
        }
      }
      else
      {
        while ( v9 )
        {
          v9 = (_DWORD *)v9[35];
          if ( --v8 <= 0 )
            goto LABEL_21;
        }
      }
    }
  }
  else
  {
    v5 = (*(int (__thiscall **)(int *))(*this + 8))(this);
    if ( v15 >= v5 )
    {
      v6 = (*(int (__thiscall **)(int *))(*this + 16))(this);
      if ( v15 >= v6 )
      {
        *((_BYTE *)this + 369) = 1;
        sub_49F690(this);
      }
      else if ( this[98] )
      {
        v7 = this[95] + (*(int (__thiscall **)(int *))(*this + 8))(this);
        if ( v15 < v7 )
        {
          sub_49F6B0(this);
          sub_4A0090(this);
        }
        else if ( v15 > v7 + this[98] )
        {
          sub_49F6F0(this);
          sub_4A0090(this);
        }
        else
        {
          *((_BYTE *)this + 370) = 1;
        }
      }
    }
    else
    {
      *((_BYTE *)this + 368) = 1;
      sub_49F670(this);
    }
  }
  if ( *((_BYTE *)this + 368) )
  {
    (*(void (__thiscall **)(int *, int))(*this + 44))(this, 1);
  }
  else
  {
    if ( *((_BYTE *)this + 369) )
    {
      (*(void (__thiscall **)(int *, int))(*this + 44))(this, 2);
      return (*(int (__thiscall **)(int *))(*this + 144))(this);
    }
    (*(void (__thiscall **)(int *, _DWORD))(*this + 44))(this, 0);
  }
  return (*(int (__thiscall **)(int *))(*this + 144))(this);
}
