int __usercall sub_403D10@<eax>(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>)
{
  int result; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // ebp
  char *v8; // eax
  int v9; // [esp+10h] [ebp-8Ch]
  int v10; // [esp+14h] [ebp-88h]
  char v11; // [esp+1Ch] [ebp-80h]
  float v12; // [esp+1Ch] [ebp-80h]
  float v13; // [esp+20h] [ebp-7Ch]
  float v14[3]; // [esp+24h] [ebp-78h] BYREF
  char *v15; // [esp+3Ch] [ebp-60h]
  char *v16; // [esp+58h] [ebp-44h]
  float v17[7]; // [esp+5Ch] [ebp-40h] BYREF
  float v18[9]; // [esp+78h] [ebp-24h] BYREF

  result = *(_DWORD *)(a1 + 316);
  v5 = *(_DWORD *)(result + 276);
  v6 = 0;
  if ( v5 )
  {
    while ( v5 != result )
    {
      if ( ++v6 > 12000 )
        return result;
      v5 = *(_DWORD *)(v5 + 276);
      if ( !v5 )
        goto LABEL_7;
    }
    sub_546C00(&unk_BE2728, 10, a3, a2);
    sub_546C00(&unk_BE2728, 11, v9, v10);
    v7 = v5;
    sub_5D7710(2, 0);
    do
    {
      v12 = *(float *)(v5 + 284);
      v15 = &byte_FFFFFF[-16777216 * (unsigned int)(unsigned __int64)(sub_402900() * v12 * -254.0)];
      v13 = *(float *)(*(_DWORD *)(v5 + 276) + 284);
      v8 = &byte_FFFFFF[-16777216 * (unsigned int)(unsigned __int64)(sub_402900() * v13 * -254.0)];
      v16 = v8;
      if ( v15 != byte_FFFFFF || v8 != byte_FFFFFF )
      {
        sub_4039C0((float *)a1, (float *)v5, v14, 0);
        return off_16C9318();
      }
      sub_4039C0((float *)a1, (float *)v5, v18, 1);
      sub_4039C0((float *)a1, *(float **)(v5 + 276), v17, 1);
      LODWORD(v18[6]) = byte_FFFFFF;
      LODWORD(v17[6]) = byte_FFFFFF;
      sub_546BC0(&unk_BE2728, 11, v18, v17);
      v5 = *(_DWORD *)(v5 + 276);
    }
    while ( v5 != v7 );
    return sub_5D7710(1, 0);
  }
  else
  {
LABEL_7:
    result = sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\ai_db.cpp", 874);
    if ( (_BYTE)result )
      return sub_561210((int)byte_FAE910, "Incomplete waypoint path", v11);
  }
  return result;
}
