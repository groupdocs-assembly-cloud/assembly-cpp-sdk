properties([
	gitLabConnection('gitlab'),
	[$class: 'ParametersDefinitionProperty', 
		parameterDefinitions: [
			[$class: 'StringParameterDefinition', name: 'branch', defaultValue: 'master', description: 'the branch to build'],
			[$class: 'StringParameterDefinition', name: 'apiUrl', defaultValue: 'https://api-qa.groupdocs.cloud', description: 'api url']
		]
	]
])

parallel windows: {
    node('windows2016') {
        try {
            gitlabCommitStatus("windows_checkout") {
                stage('windows_checkout'){
                    checkout([$class: 'GitSCM', branches: [[name: params.branch]], doGenerateSubmoduleConfigurations: false, extensions: [[$class: 'LocalBranch', localBranch: "**"]], submoduleCfg: [], userRemoteConfigs: [[credentialsId: '361885ba-9425-4230-950e-0af201d90547', url: 'https://git.auckland.dynabic.com/assembly-cloud/assembly-cpp-sdk.git']]])
                }
            }
            
            gitlabCommitStatus("windows_tests") {
                stage('windows_tests'){
                    withCredentials([usernamePassword(credentialsId: '82329510-1355-497f-828a-b8ff8b5f6a30', passwordVariable: 'AppKey', usernameVariable: 'AppSid')]) {
                        try {
                            bat 'docker build -f Dockerfile.windows -t groupdocs-assembly-cloud-cpp:windows .'
                            def apiUrl = params.apiUrl
                            bat 'runInDocker.windows.bat %AppKey% %AppSid% %apiUrl%'
                        } finally {
                            junit '**\\out\\test_result.xml'
                        }
                    }
                }
            }		
        } finally {
            bat 'docker system prune -f'
            deleteDir()
        }
    }
}, linux: {
    node('words-linux') {
        try {
            gitlabCommitStatus("linux_checkout") {
                stage('linux_checkout'){
                    checkout([$class: 'GitSCM', branches: [[name: params.branch]], doGenerateSubmoduleConfigurations: false, extensions: [[$class: 'LocalBranch', localBranch: "**"]], submoduleCfg: [], userRemoteConfigs: [[credentialsId: '361885ba-9425-4230-950e-0af201d90547', url: 'https://git.auckland.dynabic.com/assembly-cloud/assembly-cpp-sdk.git']]])
                }
            }
            
            gitlabCommitStatus("linux_tests") {
                stage('linux_tests'){
                    withCredentials([usernamePassword(credentialsId: '82329510-1355-497f-828a-b8ff8b5f6a30', passwordVariable: 'AppKey', usernameVariable: 'AppSid')]) {
                        try {
                            sh 'docker build -f Dockerfile.linux -t groupdocs-assembly-cloud-cpp:linux .'
                            sh 'docker build -f Dockerfile.tests.linux -t groupdocs-assembly-cloud-cpp-tests:linux .'
                            sh 'docker run --rm -v "$PWD/out:/out/" groupdocs-assembly-cloud-cpp-tests:linux bash groupdocs-assembly-cloud-cpp/scripts/runAll.sh $AppKey $AppSid $apiUrl'
                        } finally {
                            junit '**\\out\\test_result.xml'
                        }
                    }
                }
            }		
        } finally {
            sh 'docker system prune -f'
            deleteDir()
        }
    }
}