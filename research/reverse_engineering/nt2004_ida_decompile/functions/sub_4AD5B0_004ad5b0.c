int __thiscall sub_4AD5B0(_DWORD *this, int a2, char a3, char a4)
{
  int v5; // esi
  int v6; // eax
  int v7; // ecx
  _DWORD *v8; // eax
  int *v9; // eax
  int v10; // ebp
  int v11; // esi
  int v12; // eax
  int *v13; // eax
  int v15; // esi
  int v16; // eax
  int v18; // [esp+10h] [ebp+8h]

  v5 = this[6];
  if ( v5 )
  {
    if ( a3 )
    {
      v6 = this[147];
      if ( v6 == 8 )
      {
        v7 = 1;
        v8 = this + 139;
        do
        {
          *v8 = v8[1];
          ++v7;
          ++v8;
        }
        while ( v7 < this[147] );
      }
      else
      {
        this[147] = v6 + 1;
      }
      this[this[147] + 138] = sub_4AEF90(v5);
    }
    sub_4AF130(v5);
  }
  v9 = (int *)this[1];
  v18 = 0;
  this[3] = v9;
  if ( v9 )
  {
    v10 = *v9;
    if ( *v9 )
    {
      while ( 1 )
      {
        v11 = sub_4AEF80(v10);
        if ( v11 )
          break;
LABEL_15:
        v12 = this[3];
        if ( v12 )
          this[3] = *(_DWORD *)(v12 + 4);
        v13 = (int *)this[3];
        if ( v13 )
        {
          v10 = *v13;
          if ( *v13 )
            continue;
        }
        goto LABEL_27;
      }
      while ( v11 != a2 )
      {
        v11 = *(_DWORD *)(v11 + 56);
        if ( !v11 )
          goto LABEL_15;
      }
      if ( sub_4AF110(v10) == 1 )
        a4 = 0;
      if ( *((float *)this + 16) > 0.0 )
      {
        a4 = 0;
        this[16] = -1082130432;
      }
      sub_4AC2D0(this, v10);
      sub_4AF090(v11);
      if ( a4 )
      {
        sub_4D20D0(2, 0, 1036831949, 1);
        sub_4D20D0(0, 2, 1048576000, 0);
      }
      v18 = 1;
    }
  }
LABEL_27:
  v15 = this[6];
  if ( v15 )
  {
    v16 = sub_4AD870(this);
    if ( !(unsigned __int8)sub_4AF0B0(v16) )
      sub_4AD880(this);
    sub_4AF120(v15);
  }
  return v18;
}
