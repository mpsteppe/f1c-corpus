char __thiscall sub_4E34F0(char *this, int a2, int a3, int a4, int a5)
{
  void *v6; // eax
  char v7; // bl
  const CHAR *v8; // eax
  bool v9; // zf
  int v10; // eax
  int v11; // edi
  int v12; // ebp
  int v13; // ebx
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  const CHAR *v18; // ecx
  void **v19; // edi
  int v20; // eax
  int v22; // [esp+Ch] [ebp-4h] BYREF
  int v23; // [esp+1Ch] [ebp+Ch]
  int v24; // [esp+20h] [ebp+10h]

  v6 = (void *)*((_DWORD *)this + 2);
  v7 = 0;
  if ( v6 )
  {
    sub_5E4BF0(dword_FB1CE0, v6);
    *((_DWORD *)this + 2) = 0;
  }
  v8 = *(const CHAR **)this;
  v9 = *(_DWORD *)this == 0;
  v22 = 0;
  if ( v9 )
    v8 = WindowName;
  if ( !sub_5E7E80(dword_FB1CE0, (int)&v22, (char)v8, *((_DWORD *)this + 8), 1) && v22 )
  {
    v10 = *(_DWORD *)(v22 + 4);
    v11 = *(_DWORD *)(v22 + 8);
    v12 = v11 - a3;
    v13 = v10 - a2;
    if ( a4 > 0 && a4 < v13 )
      v13 -= a4;
    if ( a5 > 0 && a5 < v12 )
      v12 -= a5;
    v14 = 1;
    v15 = 0;
    v23 = 1;
    if ( v10 > 1 )
    {
      do
      {
        v14 = 1 << ++v15;
        v23 = 1 << v15;
      }
      while ( v10 > 1 << v15 );
    }
    v16 = 1;
    v17 = 0;
    v24 = 1;
    if ( v11 > 1 )
    {
      do
      {
        v16 = 1 << ++v17;
        v24 = 1 << v17;
      }
      while ( v11 > 1 << v17 );
    }
    v18 = *(const CHAR **)this;
    if ( !*(_DWORD *)this )
      v18 = WindowName;
    v19 = (void **)(this + 8);
    if ( sub_5E47E0(dword_FB1CE0, (int)(this + 8), (char)v18, v14, v16, *((_DWORD *)this + 8), 0, 4, 1) || !*v19 )
    {
      sub_5E4BF0(dword_FB1CE0, *v19);
      v20 = v22;
      v7 = 0;
      *v19 = 0;
    }
    else
    {
      sub_5E7540(a2, a3, *v19, 0, 0, v13, v12, 1, 0, 0);
      v20 = v22;
      v7 = 1;
      *((float *)this + 3) = (double)*(int *)(v22 + 4) / (double)v23;
      *((float *)this + 4) = (double)*(int *)(v20 + 8) / (double)v24;
      *((_DWORD *)this + 5) = *(_DWORD *)(v20 + 4);
      *((_DWORD *)this + 6) = *(_DWORD *)(v20 + 8);
    }
    sub_5E7F70(dword_FB1CE0, v20);
  }
  return v7;
}
