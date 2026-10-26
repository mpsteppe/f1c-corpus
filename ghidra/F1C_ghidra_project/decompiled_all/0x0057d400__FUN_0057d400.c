// Function: FUN_0057d400 @ 0057d400
// Strings:  [WSAGetLastError() returned an unknown value., The connection has been dropped, because of a network failure or because the system on the other end went down without notice., The network cannot be reached from this host at this time., A destination address is required., The virtual circuit was reset by the remote side executing a hard or abortive close. For UDP sockets, the remote host was unable to deliver a previously sent UDP datagram and responded with a "Port Unreachable" ICMP packet. The application should close the socket as it is no longer usable., The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable., The remote host cannot be reached from this host at this time. , The socket is message oriented, and the message is larger than the maximum supported by the underlying transport.]


char * __fastcall FUN_0057d400(int param_1)

{
  if (param_1 == -1) {
    param_1 = WSAGetLastError();
  }
  switch(param_1) {
  case 0x2714:
    return s_A_blocking_Windows_Sockets_1_1_c_005e5b10;
  default:
    return s_WSAGetLastError___returned_an_un_005e54e4;
  case 0x2719:
    return s_For_Windows_CE_AF_IRDA_sockets_o_005e5c10;
  case 0x271d:
    return s_The_requested_address_is_a_broad_005e5b60;
  case 0x271e:
    return s_The_name_or_the_namelen_paramete_005e5cf0;
  case 0x2726:
    return s_error_code___WSAEINVAL_005e5cd8;
  case 0x2728:
    return s_No_more_socket_descriptors_are_a_005e5e58;
  case 0x2733:
    return s_The_socket_is_marked_as_nonblock_005e5868;
  case 0x2734:
    return s_A_blocking_Windows_Sockets_1_1_c_005e5fb8;
  case 0x2735:
    return s_A_nonblocking_connect_call_is_in_005e5ec8;
  case 0x2736:
    return s_The_descriptor_is_not_a_socket__005e5a38;
  case 0x2737:
    return s_A_destination_address_is_require_005e55d4;
  case 0x2738:
    return s_The_socket_is_message_oriented__a_005e57f0;
  case 0x2739:
    return s_The_specified_protocol_is_the_wr_005e5c9c;
  case 0x273b:
    return s_The_specified_protocol_is_not_su_005e5df0;
  case 0x273c:
    return s_The_specified_socket_type_is_not_005e5c58;
  case 0x273d:
    return s_MSG_OOB_was_specified__but_the_s_005e5948;
  case 0x273f:
    return s_The_specified_address_family_is_n_005e6030;
  case 0x2740:
    return s_The_socket_s_local_address_is_al_005e6060;
  case 0x2741:
    return s_The_remote_address_is_not_a_vali_005e5e84;
  case 0x2742:
    return s_The_network_subsystem_or_the_ass_005e61c0;
  case 0x2743:
    return s_The_network_cannot_be_reached_fr_005e5598;
  case 0x2744:
    return s_The_connection_has_been_broken_d_005e5a98;
  case 0x2745:
    return s_The_virtual_circuit_was_terminat_005e5720;
  case 0x2746:
    return s_The_virtual_circuit_was_reset_by_005e55f8;
  case 0x2747:
    return s_No_buffer_space_is_available__Th_005e5e1c;
  case 0x2749:
    return s_The_socket_is_not_connected__con_005e5a58;
  case 0x274a:
    return s_The_socket_has_been_shut_down__i_005e58b8;
  case 0x274c:
    return s_The_connection_has_been_dropped__005e5518;
  case 0x274d:
    return s_The_attempt_to_connect_was_force_005e5dc0;
  case 0x2751:
    return s_The_remote_host_cannot_be_reache_005e57b0;
  case 0x276d:
    return s_A_successful_WSAStartup_call_mus_005e6208;
  }
}


