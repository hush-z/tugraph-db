﻿/* Copyright (c) 2022 AntGroup. All Rights Reserved. */

#pragma once
#include <iostream>
#include <utility>
#include "lgraph/lgraph_rpc_client.h"

class LgraphPythonClient {
 public:
    LgraphPythonClient(const std::string& url, const std::string& user, const std::string& password)
        : client(url, user, password) {}

    ~LgraphPythonClient() {}

    std::pair<bool, std::string> LoadPlugin(const std::string& source_file,
                                            const std::string& plugin_type,
                                            const std::string& plugin_name,
                                            const std::string& code_type,
                                            const std::string& plugin_description, bool read_only,
                                            const std::string& graph = "default",
                                            bool json_format = true, double timeout = 0) {
        std::string result;
        bool ret = client.LoadPlugin(result, source_file, plugin_type, plugin_name, code_type,
                                     plugin_description, read_only, graph, json_format, timeout);
        return {ret, result};
    }

    std::pair<bool, std::string> CallPlugin(const std::string& plugin_type,
                                            const std::string& plugin_name,
                                            const std::string& param, double plugin_time_out = 0.0,
                                            bool in_process = false,
                                            const std::string& graph = "default",
                                            bool json_format = true, double timeout = 0) {
        std::string result;
        bool ret = client.CallPlugin(result, plugin_type, plugin_name, param, plugin_time_out,
                                     in_process, graph, json_format, timeout);
        return {ret, result};
    }

    std::pair<bool, std::string> ImportSchemaFromFile(const std::string& schema_file,
                                                      const std::string& graph = "default",
                                                      bool json_format = true, double timeout = 0) {
        std::string result;
        bool ret = client.ImportSchemaFromFile(result, schema_file, graph, json_format, timeout);
        return {ret, result};
    }

    std::pair<bool, std::string> ImportDataFromFile(const std::string& conf_file,
                                                    const std::string& delimiter,
                                                    bool continue_on_error = false,
                                                    int thread_nums = 8, int skip_packages = 0,
                                                    const std::string& graph = "default",
                                                    bool json_format = true, double timeout = 0) {
        std::string result;
        bool ret =
            client.ImportDataFromFile(result, conf_file, delimiter, continue_on_error, thread_nums,
                                      skip_packages, graph, json_format, timeout);
        return {ret, result};
    }

    std::pair<bool, std::string> ImportSchemaFromContent(const std::string& schema,
                                                         const std::string& graph = "default",
                                                         bool json_format = true,
                                                         double timeout = 0) {
        std::string result;
        bool ret = client.ImportSchemaFromContent(result, schema, graph, json_format, timeout);
        return {ret, result};
    }

    std::pair<bool, std::string> ImportDataFromContent(
        const std::string& desc, const std::string& data, const std::string& delimiter,
        bool continue_on_error = false, int thread_nums = 8, const std::string& graph = "default",
        bool json_format = true, double timeout = 0) {
        std::string result;
        bool ret = client.ImportDataFromContent(result, desc, data, delimiter, continue_on_error,
                                                thread_nums, graph, json_format, timeout);
        return {ret, result};
    }

    std::pair<bool, std::string> CallCypher(const std::string& cypher,
                                            const std::string& graph = "default",
                                            bool json_format = true, double timeout = 0) {
        std::string result;
        bool ret = client.CallCypher(result, cypher, graph, json_format, timeout);
        return {ret, result};
    }

 private:
    lgraph::RpcClient client;
};
