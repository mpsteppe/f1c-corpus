char __thiscall sub_4868C0(_DWORD *this, int a2, char a3, int a4, int a5, int a6, int a7)
{
  int v8; // eax
  int v9; // edx
  int *v10; // esi
  int v11; // ecx
  int v12; // ebx
  int v13; // ebp
  char result; // al
  int v15; // ecx
  int v16; // edi
  int v17; // ebp
  int v18; // eax
  int v19; // [esp-14h] [ebp-24h]
  int v20; // [esp-Ch] [ebp-1Ch]
  int v21; // [esp+14h] [ebp+4h]
  int v22; // [esp+18h] [ebp+8h]

  v8 = sub_486460(this, a2);
  v9 = a4;
  v10 = (int *)v8;
  if ( a4 == -50000 )
  {
    a4 = this[1];
    v9 = a4;
  }
  v11 = a5;
  if ( a5 == -50000 )
    v11 = this[2];
  v12 = a6;
  if ( a6 == -50000 )
    v12 = this[3];
  v13 = a7;
  if ( a7 == -50000 )
    v13 = this[4];
  if ( v13 - v12 <= 0 || v11 - v9 <= 0 )
    return 0;
  result = 1;
  if ( v10 )
  {
    v15 = v10[2];
    v16 = v10[1] - *v10;
    v17 = v10[3] - v15;
    v21 = *v10;
    v22 = v15;
    if ( v12 < 0 )
      v21 = *v10 - v12;
    if ( v9 < 0 )
      v22 = v15 - v9;
    if ( v10[8] )
    {
      v19 = v9;
      v18 = sub_495150(&unk_7CDE00);
      sub_494A30(*(_DWORD *)(v10[8] + 12), v21, v22, v18, v12, v19, v16, v17, 0, 0);
      v9 = a4;
    }
    v20 = v9;
    sub_490920();
    sub_491960(v12, v20, v16, v17);
    return 1;
  }
  else if ( a3 )
  {
    sub_497260(v9, v11, v12, v13, 986895, 11206570);
    return 1;
  }
  return result;
}
