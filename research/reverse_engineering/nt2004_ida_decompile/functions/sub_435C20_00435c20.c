int __thiscall sub_435C20(int this)
{
  int v2; // esi
  _DWORD *v3; // edi
  char v4; // al
  void *v5; // ebp
  int result; // eax
  LPVOID *v7; // eax
  LPVOID *v8; // esi
  LPVOID **v9; // eax
  _DWORD v10[7]; // [esp+10h] [ebp-434h] BYREF
  char v11[384]; // [esp+2Ch] [ebp-418h] BYREF
  int v12; // [esp+1ACh] [ebp-298h]
  char v13; // [esp+1B0h] [ebp-294h]
  int v14; // [esp+1B8h] [ebp-28Ch]
  int v15; // [esp+1BCh] [ebp-288h]
  int v16; // [esp+1C0h] [ebp-284h]
  char String1[384]; // [esp+1C4h] [ebp-280h] BYREF
  char Source[256]; // [esp+344h] [ebp-100h] BYREF

  sub_435B70((const char **)this, (int)&unk_7663E0);
  v2 = *(_DWORD *)(this + 28);
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = (void *)*v3;
      if ( *v3 )
      {
        sub_435E40(*v3);
        sub_5BE8AE(v5);
      }
    }
    sub_5BE8AE(v3);
  }
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  result = sub_435A70((int)&unk_7663E0, Source, 256);
  if ( !result )
  {
    sub_57A080(v10);
    if ( (unsigned __int8)sub_57A2F0(Source, 1) )
    {
      memset(String1, 0, sizeof(String1));
      v12 = 0;
      v16 = 0;
      v14 = 0;
      v15 = 0;
      v13 = 1;
      while ( sub_57A490(String1, 384) )
      {
        if ( !sub_577B60(v11) && !_strcmpi(String1, off_5FE060) )
        {
          v7 = (LPVOID *)operator new(0x1Cu);
          v8 = v7;
          if ( v7 )
          {
            *v7 = 0;
            v7[1] = (LPVOID)-1;
            v7[2] = 0;
            v7[3] = (LPVOID)-1;
            v7[5] = 0;
            v7[6] = (LPVOID)-1;
            sub_435A40(v7);
            if ( sub_4357F0(v8, v10) )
            {
              sub_435A40(v8);
              if ( v8[5] )
                sub_5BE8AE(v8[5]);
              if ( v8[2] )
                sub_5BE8AE(v8[2]);
              if ( *v8 )
                sub_5BE8AE(*v8);
              sub_5BE8AE(v8);
            }
            else
            {
              v9 = (LPVOID **)operator new(0xCu);
              if ( v9 )
              {
                *v9 = v8;
                v9[1] = 0;
                *((_BYTE *)v9 + 8) = 1;
              }
              else
              {
                v9 = 0;
              }
              if ( *(_DWORD *)(this + 28) )
              {
                *(_DWORD *)(*(_DWORD *)(this + 32) + 4) = v9;
              }
              else
              {
                *(_DWORD *)(this + 28) = v9;
                *(_DWORD *)(this + 36) = v9;
              }
              *(_DWORD *)(this + 32) = v9;
              ++*(_DWORD *)(this + 40);
            }
          }
        }
      }
      sub_57A360(v10);
    }
    result = sub_57A0A0(v10);
  }
  *(_BYTE *)(this + 24) = 1;
  return result;
}
