int __stdcall sub_64AF49(unsigned int *a1, unsigned int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v6; // edx
  int v7; // edi
  unsigned int *v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // ebx
  unsigned int *v11; // ecx
  bool v12; // zf
  unsigned int v14; // [esp+4h] [ebp-14h]
  unsigned int v15; // [esp+8h] [ebp-10h]
  unsigned int v16; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  unsigned int *v18; // [esp+14h] [ebp-4h]
  unsigned int v19; // [esp+28h] [ebp+10h]
  unsigned int v20; // [esp+2Ch] [ebp+14h]

  v6 = a2;
  v7 = a5;
  v14 = a2 + a5 * a4;
  if ( a2 < v14 )
  {
    v20 = a2 + 4 * a3;
    do
    {
      v18 = a1;
      if ( v6 < v20 )
      {
        v8 = (unsigned int *)(v6 + 4);
        v16 = v6 + 4;
        v15 = ((v20 - v6 - 1) >> 3) + 1;
        do
        {
          v17 = *(unsigned int *)((char *)v8 + v7 - 4);
          v19 = *(unsigned int *)((char *)v8 + v7);
          v9 = *v8;
          v7 = a5;
          v10 = ((unsigned int)&unk_800080
               + ((v19 >> 2) & 0x3FC03FC0)
               + ((v17 >> 2) & 0x3FC03FC0)
               + ((*(v8 - 1) >> 2) & 0x3FC03FC0)
               + ((v9 >> 2) & 0x3FC03FC0))
              ^ (unsigned int)&byte_FF00FF
              & (((((unsigned int)&byte_FF00FF & v19)
                 + ((unsigned int)&byte_FF00FF & v17)
                 + ((unsigned int)&byte_FF00FF & *(v8 - 1))
                 + ((unsigned int)&byte_FF00FF & v9)
                 + 131074) >> 2)
               ^ (((v19 >> 2) & 0xFFC03FC0)
                + ((v17 >> 2) & 0xFFC03FC0)
                + ((*(v8 - 1) >> 2) & 0xFFC03FC0)
                + ((v9 >> 2) & 0xFFC03FC0)
                - 8388480));
          v11 = v18++;
          *v11 = v10;
          v8 = (unsigned int *)(v16 + 8);
          v12 = v15-- == 1;
          v16 += 8;
        }
        while ( !v12 );
        v6 = a2;
      }
      a1 = (unsigned int *)((char *)a1 + a6);
      v20 += 2 * v7;
      v6 += 2 * v7;
      a2 = v6;
    }
    while ( v6 < v14 );
  }
  return 0;
}
