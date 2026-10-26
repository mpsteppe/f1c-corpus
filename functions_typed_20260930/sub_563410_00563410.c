int __thiscall sub_563410(int this)
{
  int result; // eax
  int v3; // eax
  u_short v4; // ax
  int v5; // eax
  SOCKET v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // eax
  char *v11; // esi
  signed int v12; // eax
  unsigned int v13; // kr08_4
  int v14; // ecx
  int v15; // edi
  u_short v16; // bp
  u_short v17; // ax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int fromlen; // [esp+0h] [ebp-6FCh] BYREF
  struct timeval timeout; // [esp+4h] [ebp-6F8h] BYREF
  struct sockaddr from; // [esp+Ch] [ebp-6F0h] BYREF
  fd_set readfds; // [esp+1Ch] [ebp-6E0h] BYREF
  char buf[1212]; // [esp+120h] [ebp-5DCh] BYREF
  int v26; // [esp+5DCh] [ebp-120h]
  struct timeval v27; // [esp+5F0h] [ebp-10Ch] BYREF
  fd_set v28; // [esp+5F8h] [ebp-104h] BYREF

  if ( !this )
    return 5;
  switch ( *(_DWORD *)this )
  {
    case 1:
      v7 = *(_DWORD *)(this + 136);
      v27.tv_sec = 0;
      v27.tv_usec = 0;
      v28.fd_array[0] = v7;
      v28.fd_count = 1;
      if ( select(64, &v28, 0, 0, &v27) > 0 )
      {
        v8 = recv(*(_DWORD *)(this + 136), &byte_8CF288[dword_8CFAE0], 2047 - dword_8CFAE0, 0);
        v9 = v8;
        if ( v8 == -1 || !v8 )
        {
          closesocket(*(_DWORD *)(this + 136));
          *(_DWORD *)(this + 136) = -1;
          dword_8CFAE0 = 0;
          SetFlagIfPointerNonNull(this);
          AudioValueSetterCall(this, 3);
          result = 3;
        }
        else
        {
          if ( *(_DWORD *)(this + 1372) != -1 )
            XOREncryptionWithRollingKeyStream(v8);
          v10 = v9 + dword_8CFAE0;
          v11 = byte_8CF288;
          dword_8CFAE0 = v10;
          if ( *(_DWORD *)(this + 1372) == -1 )
          {
            if ( v10 > (byte_8CF288[0] ^ 0xEC) )
            {
              byte_8CF288[0] ^= 0xECu;
              v12 = 0;
              v13 = strlen((const char *)(this + 44)) + 1;
              if ( (int)(v13 - 1) > 0 )
              {
                do
                {
                  byte_8CF289[v12] ^= *(_BYTE *)(this + 44 + v12);
                  ++v12;
                }
                while ( v12 < (int)(v13 - 1) );
              }
              RC4KeyScheduleInitialization(this + 156);
              v11 = &byte_8CF289[byte_8CF288[0]];
              XOREncryptionWithRollingKeyStream(&byte_8CF288[dword_8CFAE0 - (_DWORD)v11]);
              v10 = dword_8CFAE0;
            }
            if ( *(_DWORD *)(this + 1372) == -1 )
              goto LABEL_47;
          }
          if ( v11 - byte_8CF288 > v10 - 6 )
          {
LABEL_47:
            dword_8CFAE0 = byte_8CF288 - v11 + v10;
            sub_58B130(byte_8CF288, v11, dword_8CFAE0);
            result = 0;
          }
          else
          {
            while ( sub_588640(v11, aFinal, 7) && !*(_DWORD *)(this + 116) )
            {
              v10 = dword_8CFAE0;
              if ( dword_8CFAE0 < 6 )
                goto LABEL_47;
              v14 = *(_DWORD *)(this + 144);
              if ( v14 == 6 || v14 == 7 )
              {
                v19 = sub_563870(&byte_8CF288[dword_8CFAE0 - (_DWORD)v11]);
                if ( v19 >= 0 )
                {
                  if ( !v19 )
                  {
                    v10 = dword_8CFAE0;
                    goto LABEL_47;
                  }
                  v11 += v19;
                }
                else
                {
                  *(_DWORD *)(this + 116) = 1;
                }
              }
              else
              {
                v15 = *(_DWORD *)v11;
                v16 = *((_WORD *)v11 + 2);
                v26 = *(_DWORD *)(this + 152);
                v11 += 6;
                v17 = ntohs(v16);
                if ( AudioNoteParamIndexSearchLoop(this, v15, v17, v26) == -1 )
                {
                  v26 = *(_DWORD *)(this + 144);
                  LOWORD(v18) = ntohs(v16);
                  ConditionalNetworkUtility((_DWORD *)this, v18, v26);
                }
              }
              v10 = dword_8CFAE0;
              if ( v11 - byte_8CF288 > dword_8CFAE0 - 6 )
                goto LABEL_47;
            }
            closesocket(*(_DWORD *)(this + 136));
            *(_DWORD *)(this + 136) = -1;
            dword_8CFAE0 = 0;
            v20 = *(_DWORD *)(this + 144);
            if ( v20 == 6 || v20 == 7 )
            {
              AudioValueSetterCall(this, 0);
              result = 0;
            }
            else
            {
              AudioValueSetterCall(this, 3);
              result = 0;
            }
          }
        }
      }
      else
      {
        result = 0;
      }
      break;
    case 2:
      timeout.tv_sec = 0;
      timeout.tv_usec = 0;
      fromlen = 16;
      while ( 1 )
      {
        readfds.fd_array[0] = *(_DWORD *)(this + 136);
        readfds.fd_count = 1;
        v3 = select(64, &readfds, 0, 0, &timeout);
        if ( v3 == -1 || !v3 )
          break;
        if ( recvfrom(*(_DWORD *)(this + 136), buf, 1499, 0, &from, &fromlen) != -1 )
        {
          HIBYTE(v28.fd_array[63]) = 0;
          if ( sub_587C20(buf, aFinal) )
          {
            v4 = ntohs(*(u_short *)from.sa_data);
            if ( TwoStepDispatch((_DWORD *)this, v4) == -1 )
            {
              LOWORD(v5) = ntohs(*(u_short *)from.sa_data);
              ConditionalNetworkUtility((_DWORD *)this, v5, 5);
            }
          }
        }
      }
      if ( GetTickCount() - *(_DWORD *)(this + 140) > 0xBB8 )
      {
        closesocket(*(_DWORD *)(this + 136));
        *(_DWORD *)(this + 136) = -1;
        AudioValueSetterCall(this, 3);
      }
      result = 0;
      break;
    case 3:
      result = sub_563AB0();
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

