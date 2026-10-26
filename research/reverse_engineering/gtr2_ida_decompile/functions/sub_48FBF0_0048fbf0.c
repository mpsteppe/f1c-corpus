int __thiscall sub_48FBF0(void *this)
{
  int result; // eax
  int v3; // ebx
  int v4; // esi
  int v5; // esi
  _DWORD *v6; // edi
  _DWORD *v7; // eax
  char *v8; // eax
  char *v9; // [esp-10h] [ebp-11Ch]
  int v10; // [esp+0h] [ebp-10Ch]
  char v11; // [esp+4h] [ebp-108h] BYREF
  __int16 v12; // [esp+5h] [ebp-107h]
  char v13; // [esp+7h] [ebp-105h]
  void *v14; // [esp+8h] [ebp-104h] BYREF
  char Buffer[256]; // [esp+Ch] [ebp-100h] BYREF

  v12 = 0;
  v14 = this;
  v11 = 0;
  v13 = 0;
  sub_4D0AC0(v10);
  sub_4CE140(this, &v14);
  result = sub_53A250(0);
  if ( result )
  {
    result = sub_616630("PrevYear");
    if ( result )
    {
      result = sub_616630("Results");
      if ( result )
      {
        v3 = sub_616630("Drivers");
        result = sub_616630("Times");
        if ( v3 )
        {
          if ( result )
          {
            v4 = sub_6165F0(result);
            result = sub_6165F0(v3);
            if ( result == v4 )
            {
              v5 = 0;
              result = sub_6165F0(v3);
              if ( result > 0 )
              {
                do
                {
                  v6 = (_DWORD *)sub_616610(v5);
                  v7 = (_DWORD *)sub_616610(v5);
                  if ( v6 )
                  {
                    if ( v7 )
                    {
                      v9 = sub_48D380(v7);
                      v8 = sub_48D380(v6);
                      sprintf(Buffer, "%s%s%s", v8, &v11, v9);
                    }
                  }
                  sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
                  ++v5;
                  result = sub_6165F0(v3);
                }
                while ( v5 < result );
              }
            }
          }
        }
      }
    }
  }
  return result;
}
